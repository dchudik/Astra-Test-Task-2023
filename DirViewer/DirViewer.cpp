#include "DirViewer.h"
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

void DirViewer::onChangeFileNameFilter(const QString newText)
{
    this->textSearchBuf = newText;
}

void DirViewer::onClickSearchFiles()
{
    this->textSearch = this->textSearchBuf;
    auto filterList = QStringList();
    // filterList.append("*.txt");
    QString filter("*" + this->textSearch + "*");
    filterList.append(filter);
    this->fileModel->setNameFilters(filterList);
    this->tree->setModel(this->fileModel);
}

QTreeView *DirViewer::buildTree(QFileSystemModel *defaultModel)
{
    auto tree = new QTreeView();

    tree->setModel(defaultModel);
    tree->setRootIndex(defaultModel->index(defaultModel->rootPath()));

    tree->setColumnWidth(0, tree->width() / 3);

    tree->setSortingEnabled(true);
    tree->sortByColumn(0, Qt::AscendingOrder);
    tree->show();

    return tree;
}

QFileSystemModel *DirViewer::buildModel()
{
    auto defaultModel = new QFileSystemModel();
    defaultModel->setRootPath(QDir::homePath());
    defaultModel->setFilter(QDir::NoDotAndDotDot | QDir::AllEntries | QDir::Hidden);
    defaultModel->setNameFilterDisables(false);

    return defaultModel;
}

DirViewer::DirViewer()
{
    this->labelName = defaultLabelName;
    this->buttonName = defaultButtonName;

    auto defaultModel = buildModel();
    this->fileModel = defaultModel;

    auto tree = buildTree(defaultModel);
    this->tree = tree;
};

void DirViewer::setButtonName(std::string name) { this->buttonName = name; };
void DirViewer::setLabelName(std::string name) { this->labelName = name; };
void DirViewer::setWindowTitle(std::string title) { this->windowTitle = title; };

DirViewer::~DirViewer()
{
    delete[] tree;
    delete[] fileModel;
};

DirViewer::DirViewer(std::string labelName, std::string buttonName, std::string windowTitle)
    : labelName(labelName), buttonName(buttonName), windowTitle(windowTitle)
{
    auto defaultModel = buildModel();
    this->fileModel = defaultModel;

    auto tree = buildTree(defaultModel);
    this->tree = tree;
};

QWidget *DirViewer::buildWidget()
{
    auto fileOrFolderName = new QLineEdit();

    QObject::connect(fileOrFolderName, &QLineEdit::textChanged, this, &DirViewer::onChangeFileNameFilter);

    auto fileOrFolderNameLabel = new QLabel();
    fileOrFolderNameLabel->setText(QString::fromStdString(this->labelName));

    auto fileOrFolderNameButton = new QPushButton();
    fileOrFolderNameButton->setText(QString::fromStdString(this->buttonName));
    QObject::connect(fileOrFolderNameButton, &QPushButton::clicked, this, &DirViewer::onClickSearchFiles);

    auto serchLayout = new QHBoxLayout();
    serchLayout->insertWidget(0, fileOrFolderNameLabel);
    serchLayout->insertWidget(1, fileOrFolderName);
    serchLayout->insertWidget(2, fileOrFolderNameButton);

    auto mainLayout = new QVBoxLayout();
    mainLayout->insertLayout(0, serchLayout);
    mainLayout->insertWidget(1, this->tree);

    auto mainWindow = new QWidget();
    mainWindow->setWindowTitle(QString::fromStdString(this->windowTitle));
    mainWindow->setLayout(mainLayout);

    return mainWindow;
}
#include <QString>
#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>

class DirViewer : public QWidget
{
private:
    // State for search
    QString textSearch = "",
        // Buffer value for LineEdit
            textSearchBuf = "";
    
    std::string labelName, buttonName;
    // Model using for display and search files
    QFileSystemModel *fileModel;
    // Component for display hierarchy files 
    QTreeView *tree;

    QFileSystemModel *buildModel();
    QTreeView *buildTree(QFileSystemModel *defaultModel);
    std::string windowTitle = "Dir Viewer";

public:
    // Default values for labels and buttons
    const std::string defaultButtonName = "Найти",
                      defaultLabelName = "Введите название файла или папки:";
    // Events
    void onChangeFileNameFilter(const QString newText);
    void onClickSearchFiles();
    // Builder for widget
    QWidget *buildWidget();
    // Setters
    void setLabelName(std::string name);
    void setButtonName(std::string name);
    void setWindowTitle(std::string title);
    // Constructors
    DirViewer();
    DirViewer(std::string labelName, std::string buttonName, std::string windowTitle);
    // Destructor
    ~DirViewer();
    
};

#ifndef CAMCAPTURE_H
#define CAMCAPTURE_H

#include <QWidget>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class CamCapture; }
QT_END_NAMESPACE

class CamCapture : public QWidget
{
    Q_OBJECT

public:
    CamCapture(QWidget *parent = nullptr);
    ~CamCapture();

private:
    Ui::CamCapture *ui;
    void CamView();
    void put_string(Mat &frame, string text, Point pt, int value);
    bool camViewFlag;
    int cnt;
    string fname;
    Mat frame;
private slots:
    void camPlay(bool);
    void snapShot();
};
#endif // CAMCAPTURE_H

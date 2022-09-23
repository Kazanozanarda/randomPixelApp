/*
*author: Ozan Arda Kazan
*02.09.22
*pixel color change with mouse
*/


#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <cstdlib>


using namespace std;
using namespace cv;


Mat canvas(1080, 1080, CV_8UC3, Scalar(0, 0, 0));
void changeColor(Mat &canvas,int x,int y) {
	
	canvas.at<Vec3b>(y, x)[0] = (int) rand()%256;
	
	canvas.at<Vec3b>(y, x)[1] = (int) rand() % 256;
	
	canvas.at<Vec3b>(y, x)[2] = (int) rand() % 256;

}

void mouse(int event,int x,int y,int flags,void* userdata) {
	if (event == EVENT_MOUSEMOVE) {
		/*
		goruntu.at<Vec3b>(y, x)[0] = (int)rand() % 256;
		goruntu.at<Vec3b>(y, x)[1] = (int)rand() % 256;
		goruntu.at<Vec3b>(y, x)[2] = (int)rand() % 256;
		*/
		changeColor(canvas, x, y);
		cout <<"X:" << x << " " <<"Y:" << y <<"|| B:"<< (int) canvas.at<Vec3b>(y, x)[0]<<" G:"<<(int) canvas.at<Vec3b>(y, x)[1]<<" R:"<< (int)canvas.at<Vec3b>(y, x)[2] << endl;
	
	}

}

class App {
public:
	string windowName= "Window";
	App(string name) {
		windowName=name;
	}

	void run() {
		while (1) {
			namedWindow(windowName, WINDOW_AUTOSIZE);
			setMouseCallback(windowName, mouse, NULL);
			imshow(windowName, canvas);
			waitKey(1);
		}
	}


};


int main() {
	App app1("Frame");
	app1.run();

	
	return 0;
}
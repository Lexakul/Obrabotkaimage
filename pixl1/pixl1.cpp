
#include <iostream>
#include <cmath>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	double h;
	//int y, x, z, I = 0, I0 = 0, OI = 0, D = 0, m1 = 0, m2 = 0, m3 = 0, m4 = 0, mm1 = 0, mm2 = 0, mm3 = 0, mm4 = 0, u2 = 0, u3 = 0, u4 = 0, o = 0, g1 = 0, g2 = 0;
	//int max = INT_MIN;
	//int min = INT_MAX;
	//int R[256];
	//for (int i = 0; i < 256; i++)
	//{
	//	R[i] = 0;
	//}
	Mat img = imread("lenna.bmp", IMREAD_GRAYSCALE); // открытия изображения IMREAD_GRAYSCALE - открытие в оттенках сером
	/*x = img.rows; // ширина
	y = img.cols; // высота
	for (int i = 0; i < x; i++) // находим макс значение пикселя (яркость)
	{
		for (int j = 0; j < y; j++)
		{
			z = img.at<uchar>(i, j); // получение доступа к пикселю (яркость)
			R[z]++; //Гистограмма шаг в 1 пиксель (Занесем яркость в z ячейку) +1
			m1 += (1 / (x * y)) * z; // нач моменты (1.2 1.3)
			m2 += (1 / (x * y)) * pow(z, 2);
			m3 += (1 / (x * y)) * pow(z, 3);
			m4 += (1 / (x * y)) * pow(z, 4);
			if (max < z)
			{
				max = z;
			}
			else
			{
				if (min > z)
				{
					min = z;
				}
			}
		}
	}
	cout << "Максимальная яркость " << max << endl;
	cout << "Минимальная яркость " << min << endl;
	cout << "Размах яркости " << max - min << endl;
	// Выполним расчеты по формулам (1.2 1.5 1.6 1.7) и сделаем вывод о близости экспериментального распределения к нормальному
	u2 = m2 - pow(m1, 2); //(1.5)
	u3 = m3 - 3 * m1 * m2 + 2 * pow(m1, 3);
	u4 = m4 - 4 * m1 * m3 + 6 * pow(m1, 2) * m2 - 3 * pow(m1, 4);
	o = sqrt(u2);
	g1 = u3 / pow(o, 3); //(1.6)
	g2 = (u4 / pow(o, 4)) - 3; //(1.7)
	//Эксперементальное распределение считают нормальным если выполняется условие
	if (((abs(g1 / (sqrt(6 / (x * y))))) && (abs(g2 / sqrt(24 / x * y)))) <= 3)
	{
		cout << "Экспериментальное распределение нормальное " << endl;
	}
	else
	{
		cout << "Экспериментальное распределение ненормальное " << endl;
	}
	// Убедимся что оценки полученные по формулам (1.3)(1.4) совпадают (1.3=1.2)

	for (int h = 0; h <= max; h++) //(1.4)
	{
		mm1 += (1 / (x * y)) * h * R[h]; //(1.4) 
		mm2 += (1 / (x * y)) * pow(h, 2) * R[h];
		mm3 += (1 / (x * y)) * pow(h, 3) * R[h];
		mm4 += (1 / (x * y)) * pow(h, 4) * R[h];
	}
	if ((m1==mm1) && (m2 == mm2)&& (m3 == mm3)&& (m4 == mm4))
	{
		cout << "Сходятся" << endl;
	}
	else
	{
		cout << "Не сходятся " << endl;
	}
	//энтропия
	for (int h = 0; h <= max; h++)
	{
		I += log2(x * y) - (1/(x*y)) * R[h] * log2(R[h]); 
	}
	I0 = log2(max - min + 1);
	//относительная энтропия
	OI = I / I0;
	//избыточность предложенного изображения
	D = 1 - (I / I0);*/
	Mat kernel1 = (Mat_<double>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1);
	//kernel1 = kernel1/16;
	Mat identity;
	filter2D(img, identity, -1, kernel1);
	imshow("Original", img);
	imshow("Identity", identity);
	waitKey();
	imwrite("identity.jpg", identity);
	destroyAllWindows();
}


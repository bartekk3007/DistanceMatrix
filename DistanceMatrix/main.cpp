#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

double toRadian(double degree)
{
	return degree * M_PI / 180.0;
}

double toDegree(double radian)
{
	return radian * (180.0 / M_PI);
}

double calculateLength(const vector<double>& vLan, const vector<double>& vLon, int index0, int index1)
{
	double c1 = cos(toRadian(90 - vLan[index0]));
	double c2 = cos(toRadian(90 - vLan[index1]));
	double s1 = sin(toRadian(90 - vLan[index0]));
	double s2 = sin(toRadian(90 - vLan[index1]));
	double c3 = cos(toRadian(vLon[index0] - vLon[index1]));

	double sum = c1 * c2 + s1 * s2 * c3;
	double radian = acos(sum);
	double convDegree = toDegree(radian);
	double length = convDegree * 111.1;
	return length;
}

int main()
{
	vector<string> vAbbr = {"POG", "JAG", "LPO", "WAR", "LEG", "WID", "£KS", "RAD", "ZLU", "ŒL¥", "KOR", "RAK", "PIA", "GZA", "RCH", "SMI", "CRA", "PNI"};
	vector<double> vLatitude = {53.44, 53.11, 52.40, 52.23, 52.22, 51.77, 51.76, 51.41, 51.41, 51.14, 50.86, 50.78, 50.31, 50.30, 50.29, 50.30, 50.06, 50.03};
	vector<double> vLongitude = {14.52, 23.15, 16.86, 16.38, 21.04, 19.51, 19.43, 21.17, 16.20, 16.94, 20.63, 19.16, 18.70, 18.77, 18.97, 21.44, 19.92, 20.22};

	cout << calculateLength(vLatitude, vLongitude, 0, 2);

	ofstream ost("wyniki.txt");

	for (const auto& elem : vAbbr)
	{
		ost << elem << '\t';
	}
	ost << '\n';

	vector<vector<double>> vAll;
	for (int i = 0; i < 18; i++)
	{
		vector<double> vTeam;
		for (int j = 0; j < 18; j++)
		{
			vTeam.push_back(calculateLength(vLatitude, vLongitude, i, j));
			ost << calculateLength(vLatitude, vLongitude, i, j) << '\t';
		}
		vAll.push_back(vTeam);
		ost << '\n';
	}

	return 0;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include "ui_mainWindow.h"
#include "qcustomplot.h" // the header file of QCustomPlot.
#define PI 3.1415926

class MainWindow;

class MainWindow : public QMainWindow, Ui::MainWindow
{

  Q_OBJECT

	public:
		MainWindow(QWidget *parent=0);

	private slots:
		void getParams();
		void plotOrbit();
		void replotOrbit();

	private:
		double m1, m2, e, a;	// masses, eccentricity, semi-major axis
		static const int Ntheta=500;
		double theta[Ntheta];
		

};

#endif

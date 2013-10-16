
#include "mainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), bin(new binary)
{
	setupUi(this);
	//setGeometry(400, 250, 542, 390);

// define theta
	double dth = PI / (Ntheta);
	for(int i=0; i<Ntheta; i++)
		theta[i] = i*dth;

// set up regexp validator so numerical inputs can only be numbers
	QRegExp regExp1("[1-9][0-9.]{0,3}");
	mass1Edit->setValidator(new QRegExpValidator(regExp1, this));
	mass2Edit->setValidator(new QRegExpValidator(regExp1, this));
	smaEdit->setValidator(new QRegExpValidator(regExp1, this));

// set up more restrictive input for eccentricity
	QRegExp regExp2("[0][.][0-9 ]{0,3}");
	eccEdit->setValidator(new QRegExpValidator(regExp2, this));
	eccEdit->setInputMask("\\0\\.999");	// input mask for eccEdit to force input of the from 0.xxx, where the //0//. means 0 and . cannot be deleted

// connections
	connect(eccEdit,SIGNAL(returnPressed()),this,SLOT(replotTwoBodyOrbits()));
	connect(mass1Edit,SIGNAL(returnPressed()),this,SLOT(replotTwoBodyOrbits()));
	connect(mass2Edit,SIGNAL(returnPressed()),this,SLOT(replotTwoBodyOrbits()));
	connect(smaEdit,SIGNAL(returnPressed()),this,SLOT(replotTwoBodyOrbits()));

// get initial binary values
	getParams();
	plotTwoBodyOrbits();
}


// getParams: collect required binary parameters from lineEdits
void MainWindow::getParams()
{
	bin->set_m1( (mass1Edit->text()).toDouble() );
	bin->set_m2( (mass2Edit->text()).toDouble() );
	bin->set_a ( (smaEdit->text()).toDouble() );
	bin->set_ecc( (eccEdit->text()).toDouble() );
}

void MainWindow::replotTwoBodyOrbits()
{
	getParams();
	plotTwoBodyOrbits();
}

void MainWindow::plotTwoBodyOrbits()
{
	QVector<double> x1top(Ntheta,0), y1top(Ntheta,0), x1bot(Ntheta,0), y1bot(Ntheta,0);
	QVector<double> x2top(Ntheta,0), y2top(Ntheta,0), x2bot(Ntheta,0), y2bot(Ntheta,0);
	double num1 = bin->get_a1()*(1.0-bin->get_ecc()*bin->get_ecc());
	double num2 = bin->get_a2()*(1.0-bin->get_ecc()*bin->get_ecc());

	for(int i=0; i<Ntheta; i++)
	{
		x1top[i] = num1 / (1.0 + bin->get_ecc()*cos(theta[i])) * cos(theta[i]);
		y1top[i] = num1 / (1.0 + bin->get_ecc()*cos(theta[i])) * sin(theta[i]);
		x1bot[Ntheta-i-1] = x1top[i];
		y1bot[Ntheta-i-1] = -y1top[i];
		x2top[i] = -num2 / (1.0 + bin->get_ecc()*cos(theta[i])) * cos(theta[i]);
		y2top[i] = -num2 / (1.0 + bin->get_ecc()*cos(theta[i])) * sin(theta[i]);
		x2bot[Ntheta-i-1] = x2top[i];
		y2bot[Ntheta-i-1] = -y2top[i];

	}


  // create graph and assign data to it:
  customPlot->addGraph();
  customPlot->graph(0)->setData(x1top, y1top);
  customPlot->addGraph();
  customPlot->graph(1)->setData(x1bot, y1bot);
  customPlot->addGraph();
  customPlot->graph(2)->setPen(QPen(Qt::red));
  customPlot->graph(2)->setData(x2top, y2top);
  customPlot->addGraph();
  customPlot->graph(3)->setPen(QPen(Qt::red));
  customPlot->graph(3)->setData(x2bot, y2bot);
  // give the axes some labels:
  customPlot->xAxis->setLabel("x");
  customPlot->yAxis->setLabel("y");

  // set axes ranges, so we see all data:
  // determine width of graph so we can manually implement a square viewing perspective
  customPlot->replot();
  customPlot->rescaleAxes();
  int w = (customPlot->axisRect())->width();
  int h = (customPlot->axisRect())->height();
  double rat = fabs((double)w/(double)h);
//qDebug("w = %d, h = %d, rat = %.5f",w,h,rat);

 // double sMinAx = MAX(bin->get_a1(),bin->get_a2())*sqrt(1-bin->get_ecc()*bin->get_ecc());	// semi-MINOR axis
  double apo = MAX(bin->get_a1(),bin->get_a2()) * (1+bin->get_ecc());
  double xlim, ylim;
	xlim = apo*rat;	
	ylim = apo;

  customPlot->xAxis->setRange(-xlim,xlim);
  customPlot->yAxis->setRange(-ylim,ylim);
  customPlot->replot();
}	

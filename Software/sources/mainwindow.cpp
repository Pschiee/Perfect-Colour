/**
 * @file mainwindow.cpp
 * @author Callum Mason + Silviya Ivanova
 * @brief The Main window for the app
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "includes/mainwindow.h"
#include "ui_mainwindow.h"
#include "includes/selectcolour.h"
#include "includes/paint.h"
#include "includes/cleanpaint.h"
#include "includes/chosen_colour.h"

#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFile>
#include <QImage>
#include <QMessageBox>
#include <QInputDialog>

#include <wiringPi.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    QMainWindow::showFullScreen(); // Set size of main window to full screen size
    QPixmap pic(":/img/img/Perfect_Colour_Logo_02.png"); // Find logo in resources
    int w=ui->label_logo->width(); // get width of the label used for displaying the logo
    int h=ui->label_logo->height(); // get the height of the label used for displaying the logo
    ui->label_logo->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio)); // Keep the aspect ratio of the logo when resizing
    ui->label_logo->setScaledContents(true); // Display logo
    QPalette p = ui ->colour_selected -> palette(); // Set area for the selected colour to be displayed
    p.setColor(QPalette::Base, QColor(255,255,255)); // Set background to RGB (255,255,255)
    ui -> colour_selected -> setPalette(p); // Shows the colour selected in display area
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
	bool ok = 0; // Refers to validity of amount selected
	amount = QInputDialog::getDouble(this, "Amount", "Amount Selected",0,0,10,2,&ok); // Provides a dialog window for input amount from user

	if (ok == 1) { // Is amount selected valid
    QColor color = chosenColour.get_colour(); // Gets the colour selected
	  paint paint; // Paint object
    connect(this,SIGNAL(sent(QColor,double)), &paint, SLOT(received(QColor,double))); // Links to colour selected
    emit sent(color,amount); // Sends colour and amount selected
    paint.setModal(true); // Starts dispensing process
    paint.exec(); // Executes code for dispensing
  }
}

void MainWindow::on_pushButton_3_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white,this, "Choose colour"); // Opens a Colour Dialogue for the user to select a colour
    store(color); // Stores the colour selected

    if (color.isValid()){ // Check validity of colour selected
        QPalette p = ui ->colour_selected -> palette(); // Set area for the selected colour to be displayed
        p.setColor(QPalette::Base, QColor(color)); // Sets the basecolour to be the colour selected
        ui -> colour_selected -> setPalette(p); // Shows the colour selected in display area
        chosenColour.set_colour(color); // Stores the selected colour
    }
}

void MainWindow::on_pushButton_4_clicked()
{
      selectcolour selectcolour; // Loads selectcolour dialog
      connect(&selectcolour,SIGNAL(send(QColor)), this, SLOT(receive(QColor))); // Connects the main window and the browse
      selectcolour.setModal(true); // Open selectcolour
      selectcolour.exec(); // Pop up as a modal dialog
}


void MainWindow::on_pushButton_5_clicked()
{
    this->close(); //Close app
}

void MainWindow::on_pushButton_clicked()
{
    QPalette w; // Load colour
    ui->colour_selected->setPalette(w); // Show colour on the screen
}

void MainWindow::receive(QColor color)
{
    chosenColour.set_colour(color); // Sets selected colour to be the colour received
    QPalette p = ui ->colour_selected -> palette();  // Set area for the selected colour to be displayed
    p.setColor(QPalette::Base, color); // Sets the basecolour to be the colour selected
    ui -> colour_selected -> setPalette(p); // Shows the colour selected in display area
}

void MainWindow::on_pushButton_6_clicked()
{
    cleanpaint cleanpaint; // Load cleanpaint dialog
    cleanpaint.setModal(true); // Open cleanpaint window
    cleanpaint.exec(); // Execute
}


void MainWindow::on_actionApp_Help_triggered()
{
    QMessageBox::information(this, "Welcome to our help menu", "<font size = 2><p>The main window of our application shows the Perfect Colour logo and "
                                                               "the colour selected from you in the box on the top right which stays white until another has been selected.Below"
                                                               " you can see six buttons which allow actions to select from."
                                                               "<h3>Open Colour Window</h3><p>Allows you to open the colour wheel from which you can"
                                                               " select a colour. Press OK and this will send you back to our main page and the colour of the box in the top right "
                                                               "will change to the one selected by you. Proceed to the paint dispensing process by "
                                                               "clicking on the Mix button.</p> <h3>Browse</h3> <p>Allows you to access your own computer directories. From there you can select your own photo and colour from it."
                                                               "</p><h3>Clear</h3><p>This button clears the colour selected in case you want to change it.</p>"
                                                               "<h3>Mix</h3><p>Pressing this button will open the mixing window</p>"
                                                               "<h3>Clean/Refill a Syringe</h3><p> Opens another window for refilling or cleaning a syringe</p>"
                                                               "<h3>Close App</h3><p>Closes the Perfect Colour app.</p><p>For more help visit our Wiki Help Page <a "
                                                               "href='https://github.com/Pschiee/Perfect-Colour/wiki/User-Manual'>HERE.</a>&nbsp;</p> </font>"  );
    // Displays a help message for users
}



void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "Learn more about Perfect Colour here...", "<h1><strong>Find more about Perfect Colour here!</strong></span></h1><p>We are a "
                                                                                                         "team of three final year students at the University of Glasgow and we are extremely happy to "
                                                                                                         "present our Real Time Embedded Programming project to you! Welcome to the one-of-a-kind acrylic "
                                                                                                         "paint dispensing machine! It can dispense any colour selected by you either by using our colour "
                                                                                                         "wheel or the colour of a pixel from you own photo!</p><h2><strong>Project "
                                                                                                         "Page:</strong></h2><p>On our Github project age you would be able to find all"
                                                                                                         " information needed to build your own paint dispensing machine. Moreover, "
                                                                                                         "you will be able to meet our team, visit our Github page &nbsp;</p> <p><a "
                                                                        "href='https://github.com/Pschiee/Perfect-Colour'>Check out our project page here.</a>&nbsp;</p>");
    // Displays an about message for users
}

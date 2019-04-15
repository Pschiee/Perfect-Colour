/**
 * @file selectcolour.h
 * @author Callum Mason + Silviya Ivanova + Leire Froufe Vigara
 * @brief The class selectcolour provides the browse window allowing you to select colour from an image.
 * @date 2019-04-12
 *
 * @copyright Copyright (c) 2019
 *
 */

#ifndef SELECTCOLOUR_H
#define SELECTCOLOUR_H

#include <QDialog>
#include <QMouseEvent>
#include <QDebug>
#include <QEvent>
#include <QLabel>
#include <QResizeEvent>
#include <QFileDialog>
#include <QColor>


namespace Ui {
  /**
* @brief The class selectcolour provides the browse window allowing you to select colour from an image.
*/
class selectcolour;
}
/**
* @brief The class selectcolour provides the browse window allowing you to select colour from an image.
*/
class selectcolour : public QDialog
{
    Q_OBJECT

public:

  /**
   * @brief Construct a new selectcolour object
   *
   * @param parent
   */
    explicit selectcolour(QWidget *parent = nullptr);
    ~selectcolour();

    /**
     * @brief Function used to get the file name that is wanted. This is stored in the variable filename.
     */
    void getName() {
        QString name = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg)"));
        filename = name;
         }

    /**
     * @brief Function used toload the image. This is then stored in the variable image
     */
    void loadImage() {
        QImage tempimage;
        tempimage.load(filename);
        image = tempimage.copy();
        }

protected:

private slots:

  /**
     * @brief Browse for the image and display selected image
     */
    void on_pushButton_clicked();

    /**
     * @brief Confirm the selected colour and return to the main window.
     */
    void on_Confirm_clicked();

    /**
     * @brief Takes the colour of the pixel that the mouse is on. Then sends this to the main window.
     */
    void Mouse_current_pos();

signals:
      /**
        * @brief Send the selected colour to the main window.
        */
        void send(QColor Colour);

private:
    Ui::selectcolour *ui;
    QString filename; ///< Create new QString object
    QImage image; ///< Create new QImage object
    QColor colour; ///< Creates new QColor object
};  

#endif // SELECTCOLOUR_H

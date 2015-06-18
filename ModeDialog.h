
#ifndef MODE_DIALOG_H
#define MODE_DIALOG_H

#include "ui_ModeDialog.h"

/**
 * Qt Dialog to select the appropriate datatype.
 */
class ModeDialog : public QDialog, protected Ui_ModeDialog
{
	Q_OBJECT
public:

	/** Supported type */
	typedef enum {
		CLASSICAL_STILL = 88,
		DISTANT_VIDEO = 99
	} Mode;

    ModeDialog(QWidget* parent = 0, Qt::WindowFlags flags = 0);
	virtual ~ModeDialog();
	Mode getMode() { return this->mode; }

public slots:
	/** 
    * Event handler - triggered when radio button item is clicked.
	* Sets the datatype.
    */
	void modeButtonClicked();

private:
	Mode	mode;
};
#endif // !MODE_DIALOG_H

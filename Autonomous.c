#include "autoControl.h"
#include "autoCode.h"
//include files - autoControl contains the functions required to run. autoCode is the data recorded.

//rotation sensor = 627.2 counts per rotation.
// buttons Left = 1   Center = 2   Right = 4
//this code selects an autonomous function for a starting poing. Displays dialog as follows

// 1)														2)										3)													4)
//       Which Color?								(Color) Team?						(Color)- Which Side?			(Color) (Side)
//		Red						Blue					Red		OK		Blue				  Front				    Back			Front OK Back

void Autonomous() {
	clearLCDLine(0);
 	clearLCDLine(1);

  displayLCDPos(0, 0);
  displayNextLCDString("  Which Color?  ");

 	displayLCDPos(1, 0);
 	displayNextLCDString("Red");

 	displayLCDPos(1, 12);
 	displayNextLCDString("Blue");
 	int choice = -1;
 	int pos = -1;
 	while (1) {
 		choice = nLCDButtons;
 		if(choice == 1 || choice == 4)
 			break;
	}
	displayLCDPos(1, 7);
 	displayNextLCDString("OK");
	clearLCDLine(0);
	displayLCDPos(0, 0);
	int choiceOld;
	while (1) {
		if (choice == 1 && choiceOld != 1) {
			clearLCDLine(0);
			displayNextLCDString("Red Team?");
			choiceOld = 1;
			pos = 0;
		} else if (choice == 4 && choiceOld != 4) {
			clearLCDLine(0);
		 	displayNextLCDString("Blue Team?");
		 	choiceOld = 4;
		 	pos = 1;
		} else if (choice == 2) {
			break;
		}
		choice = nLCDButtons;
	}
	//==============================================
	//				CHOOSE FRONT OR BACK
	//==============================================


	clearLCDLine(0);
 	clearLCDLine(1);

  displayLCDPos(0, 0);
  if (pos == 0)
  	displayNextLCDString("Red- Which Side?");
  if (pos == 1)
  	displayNextLCDString("Blue- Which Side?");

 	displayLCDPos(1, 0);
 	displayNextLCDString("Front");
 	int newPos = -1;
 	displayLCDPos(1, 12);
 	displayNextLCDString("Back");
 	while (1) {
 		choice = nLCDButtons;
 		if(choice == 1 || choice == 4)
 			break;
	}
	newPos = choice;
	displayLCDPos(1, 7);
 	displayNextLCDString("OK");
	clearLCDLine(0);
	displayLCDPos(0, 0);
	choiceOld = 0;
	while (1) {
		if (choice == 1 && choiceOld != 1) {
			clearLCDLine(0);
			if (pos == 0)
				displayNextLCDString("Red Front?");
			if (pos == 1)
  			displayNextLCDString("Blue Front?");
			choiceOld = 1;
			newPos = 0;
		} else if (choice == 4 && choiceOld != 4) {
			clearLCDLine(0);
		 	if (pos == 0)
				displayNextLCDString("Red Back?");
			if (pos == 1)
  			displayNextLCDString("Blue Back?");
		 	choiceOld = 4;
		 	newPos = 1;
		} else if (choice == 2) {
			break;
		}
		choice = nLCDButtons;
	}
	pos += 2 * newPos;
	clearLCDLine(0);

	//runs the function for the starting spot you selected
	if (pos == 0)
		AutoRF();
	if (pos == 1)
		AutoBF();
	if (pos == 2)
		AutoRB();
	if (pos == 3)
		AutoBB();
}

#include "autoControl.h"
#include "autoCode.h"
//include files - autoControl contains the functions required to run. autoCode is the data recorded.

//rotation sensor = 627.2 counts per rotation.
// buttons Left = 1   Center = 2   Right = 4
//this code selects an autonomous function for a starting poing. Displays dialog as follows

// 1)														2)										3)													4)
//       Which Color?								(Color) Team?						(Color)- Which Side?			(Color) (Side)
//		Red						Blue					Red		OK		Blue				  Front				    Back			Front OK Back

void AutoSelector() {
	clearLCDLine(0);
 	clearLCDLine(1);

  displayLCDPos(0, 0);
  displayNextLCDString("  Which Dir?  ");

 	displayLCDPos(1, 0);
 	displayNextLCDString("Left");

 	displayLCDPos(1, 11);
 	displayNextLCDString("Right");
 	int choice = -1;
 	pos = -1;
 	while (1) {
 		choice = nLCDButtons;
 		if(choice == 1 || choice == 4)
 			break;
	}
	pos = choice / 4;

	/*clearLCDLine(0);
 	clearLCDLine(1);

  displayLCDPos(0, 0);
  displayNextLCDString("  Which Color?  ");

 	displayLCDPos(1, 0);
 	displayNextLCDString("Red");

 	displayLCDPos(1, 12);
 	displayNextLCDString("Blue");
 	int choice = -1;
 	pos = -1;
 	while (1) {
 		choice = nLCDButtons;
 		if(choice == 1 || choice == 4)
 			break;
	}
	pos = choice / 4;
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
 	displayNextLCDString("Skyrise");
 	displayLCDPos(1, 12);
 	displayNextLCDString("Post");

 	choice = -1;

 	while (nLCDButtons == 1 || nLCDButtons == 4);

 	while (1) {
 		choice = nLCDButtons;
 		if(choice == 1 || choice == 4)
 			break;
	}
	int newPos = choice / 4;
	pos += 2 * newPos;
	clearLCDLine(0);
	// */
	//runs the function for the starting spot you selected
	clearLCDLine(0);
 	clearLCDLine(1);

  displayLCDPos(0, 0);

  wait1Msec(1000);

}

void Autonomous() {
	if (pos == 0) {
		displayNextLCDString("Left");
		AutoRedPost();
  } else if (pos == 1) {
    displayNextLCDString("Right");
		AutoBluePost();
  } /*if (pos == 2) {
		AutoRedPost();
		displayNextLCDString("Red Post");
  } if (pos == 3) {
		AutoBluePost();
		displayNextLCDString("Blue Post");
	} // */
}

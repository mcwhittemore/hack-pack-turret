//this is where we store global variables!
#define PASSCODE_LENGTH 5
#define CORRECT_PASSCODE "LURDK" // Change this to your desired passcode
char passcode[PASSCODE_LENGTH + 1] = ""; // Buffer to store user input passcode
bool passcodeEntered = false; // Flag to indicate if passcode has been entered correctly
                              //
int handlePasswordMode() {
  if (strlen(inputBuffer) != PASSCODE_LENGTH){
    return 0;
  } 

  if (strcmp(inputBuffer, CORRECT_PASSCODE) == 0) {
    shakeHeadYes();
    return DIRECT_MODE;
  } else {
    shakeHeadNo();
    return -1;
  }
}

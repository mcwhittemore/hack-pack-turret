//this is where we store global variables!
#define PASSCODE_LENGTH 4
#define CORRECT_PASSCODE "4888" // Change this to your desired passcode
char passcode[PASSCODE_LENGTH + 1] = ""; // Buffer to store user input passcode
bool passcodeEntered = false; // Flag to indicate if passcode has been entered correctly
                              //
void checkPasscode() {
    if (strcmp(passcode, CORRECT_PASSCODE) == 0) {
        // Correct passcode entered, shake head yes
        Serial.println("CORRECT PASSCODE");
        passcodeEntered = true;
        shakeHeadYes();
    } else {
        // Incorrect passcode entered, shake head no
        passcodeEntered = false;
        shakeHeadNo();
        Serial.println("INCORRECT PASSCODE");
    }
    passcode[0] = '\0'; // Reset passcode buffer
}

void addPasscodeDigit(char digit) {
    if (!passcodeEntered && digit >= '0' && digit <= '9' && strlen(passcode) < PASSCODE_LENGTH) {
        strncat(passcode, &digit, 1); //adds a digit to the passcode
        Serial.println(passcode); //print the passcode to Serial
    } else if (strlen(passcode) > PASSCODE_LENGTH+1){
      passcode[0] = '\0'; // Reset passcode buffer
      Serial.println(passcode);
    }
}

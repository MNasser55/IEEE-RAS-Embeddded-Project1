//added By Nasser
int safeInputInt(const char *prompt) { // this function made for make sure the input is num not character (for int)
    char buffer[100];
    int value;
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &value) == 1) { //here when sscan see a character will failed and return 0
            return value;
        } else {
            printf("Invalid input! Please enter a number.\n");
        }
    }
}

float safeInputFloat(const char *prompt) {// this function made for make sure the input is num not character but (for float)
    char buffer[100];
    float value;
    while (1) {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%f", &value) == 1) {//here when sscan see a character will failed and return 0
            return value;
        } else {
            printf("Invalid input! Please enter a valid amount.\n");
        }
    }
}
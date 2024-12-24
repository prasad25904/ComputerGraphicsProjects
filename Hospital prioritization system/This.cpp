#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <GL/gl.h>
#include <GL/glut.h>


struct node {
    int priority;
    int info;
    char name[20];
    char mobile[15];
    char address[50];
    int age;
    char time[20];
    struct node *next;
} *front = NULL;


#define MAX_NAME_LENGTH 20
#define MAX_MOBILE_LENGTH 15
#define MAX_ADDRESS_LENGTH 50
#define MAX_TIME_LENGTH 20

int screenWidth = 800;
int screenHeight = 600;
int selectedOption = 1;
int selectedPriority = 0;



void initializeFromFile() {
    FILE *file = fopen("patient.txt", "r");
    if (file != NULL) {
        while (!feof(file)) {
            struct node *tmp = (struct node *)malloc(sizeof(struct node));
            if (fscanf(file, "%s %s %s %d %d %d %19[^\n]\n", tmp->name, tmp->mobile, tmp->address, &tmp->age, &tmp->info, &tmp->priority, tmp->time) == 7) {
                struct node *ptr = front;
                struct node *prev = NULL;
                // Traverse the list to find the correct position to insert the new node
                while (ptr != NULL && tmp->priority >= ptr->priority) {
                    prev = ptr;
                    ptr = ptr->next;
                }
                // Insert the new node at the correct position
                if (prev == NULL) {
                    tmp->next = front;
                    front = tmp;
                } else {
                    prev->next = tmp;
                    tmp->next = ptr;
                }
            } else {
                free(tmp); // Free the allocated memory if fscanf fails
            }
        }
        fclose(file);
    }
}

void saveToFile() {
    FILE *file = fopen("patient.txt", "w");
    
    if (file != NULL) {
        struct node *ptr = front;
        while (ptr != NULL) {
            fprintf(file, "%s %s %s %d %d %d %s\n", ptr->name, ptr->mobile, ptr->address, ptr->age, ptr->info, ptr->priority, ptr->time);
            ptr = ptr->next;
        }
        fclose(file);
    }
}

void insert() {
    struct node *tmp, *ptr, *prev;
    int token, ip;
    char name[20], mobile[15], address[50];
    int age;
    time_t now;
    struct tm *timestamp;

    tmp = (struct node *)malloc(sizeof(struct node));

    printf("\n ENTER NAME: ");
    scanf("%s", name);
    strcpy(tmp->name, name);

    printf("\n ENTER MOBILE NUMBER: ");
    scanf("%s", mobile);
    strcpy(tmp->mobile, mobile);

    printf("\n ENTER ADDRESS: ");
    scanf(" %[^\n]s", address);
    strcpy(tmp->address, address);

    printf("\n ENTER AGE: ");
    scanf("%d", &age);
    tmp->age = age;

    printf("\n ENTER THE TOKEN NUMBER: ");
    scanf("%d", &token);

    printf("\n\n ENTER THE PRIORITY \n1 for emergency\n2 for visiting\n3 for regular checkup \n4 for medicine\n ENTER : ");
    scanf("%d", &ip);

    tmp->info = token;
    tmp->priority = ip;

    now = time(NULL);
    timestamp = localtime(&now);
    strftime(tmp->time, sizeof(tmp->time), "%Y-%m-%d %H:%M:%S", timestamp);

    ptr = front;
    prev = NULL;

    // Traverse the list to find the correct position to insert the new node
    while (ptr != NULL && ip >= ptr->priority) {
        prev = ptr;
        ptr = ptr->next;
    }

    // Insert the new node at the correct position
    if (prev == NULL) {
        tmp->next = front;
        front = tmp;
    } else {
        prev->next = tmp;
        tmp->next = ptr;
    }

    saveToFile();
}

void deleteNext() {
    if (front == NULL) {
        printf("\n\n NO MORE PATIENTS\n");
        return;
    }
    struct node *tmp = front;
    printf("\n\n DELETED TOKEN NUMBER %d\n", tmp->info);
    front = front->next;
    free(tmp);
}
void display(int priority) {
    struct node *ptr = front;
    if (front == NULL) {
        printf("\n\nLIST IS EMPTY, NO PATIENTS\n");
    } else {
        printf("PRIORITY\tNAME\t\tTOKEN NUMBER\t\tMOBILE\t\t\tADDRESS\t\tAGE\t\tTIME\n\n");
        while (ptr != NULL) {
            if (priority == 0 || ptr->priority == priority) {
                printf("%d\t\t%-20s\t%-10d\t%-15s\t%-20s\t%-d\t%s\n", ptr->priority, ptr->name, ptr->info, ptr->mobile, ptr->address, ptr->age, ptr->time);
            }
            ptr = ptr->next;
        }
    }
}
void search() {
    int tokenToSearch;
    printf("Enter token : ");
    scanf("%d",&tokenToSearch);
    FILE *file = fopen("patient.txt", "r");
    
    if (file == NULL) {
        printf("\n Error opening file.");
        return;
    }

    char line[200];
    int found = 0;

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        int token;
        sscanf(line, "%*s %*s %*s %*s %d", &token);
        
        // Check if the token matches the one being searched
        if (token == tokenToSearch) {
            printf("\n Patient found:\n");
            printf("%s", line); // Print the line containing patient data
            found = 1;
        }
    }

    fclose(file);

    if (!found) {
        printf("\n Patient with token number %d not found in file.\n", tokenToSearch);
    }
}


void update() {
    int token, newPriority;
    printf("\n ENTER TOKEN NUMBER of the patient to update: ");
    scanf("%d", &token);

    struct node *ptr = front;
    struct node *prev = NULL;
    struct node *tmp = NULL;

    // Search for the patient with the given token number
    while (ptr != NULL) {
        if (ptr->info == token) {
            tmp = ptr;
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    if (tmp == NULL) {
        printf("\n Patient not found\n");
        return;
    }

    printf("\n Enter new priority: ");
    scanf("%d", &newPriority);
    tmp->priority = newPriority;

    // If the patient's new priority is higher than the previous one, move them towards the top of the queue
    if (prev != NULL && newPriority > prev->priority) {
        prev->next = tmp->next;
        tmp->next = front;
        front = tmp;
    } else {
        // Otherwise, traverse the list to find the correct position based on the new priority
        ptr = front;
        prev = NULL;
        while (ptr != NULL && newPriority <= ptr->priority) {
            prev = ptr;
            ptr = ptr->next;
        }
        // Insert the patient at the correct position
        if (prev == NULL) {
            tmp->next = front;
            front = tmp;
        } else {
            prev->next = tmp;
            tmp->next = ptr;
        }
    }

    printf("\n Patient information updated successfully\n");
    saveToFile();

     

}

void statistics() {
    struct node *ptr = front;
    int count = 0;
    double totalWaitTime = 0;

    while (ptr != NULL) {
        totalWaitTime += ptr->priority;
        count++;
        ptr = ptr->next;
    }

    printf("\n Total Patients in the queue: %d\n", count);
    printf(" Average Wait Time: %.2lf\n", totalWaitTime / count);
}


void deleteFromFile(int tokenToDelete) {
    FILE *file = fopen("patient.txt", "r");
    FILE *tempFile = fopen("temp.txt", "w");
    
    if (file == NULL || tempFile == NULL) {
        printf("\n Error opening file.");
        return;
    }

    int token;
    char line[200];
    int found = 0;

    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%*s %*s %*s %*d %d", &token);
        
        // Check if the token matches the one to be deleted
        if (token == tokenToDelete) {
            found = 1; // Flag indicating the patient is found and deleted
            continue; // Skip writing this line to the temporary file
        }

        // Write the line to the temporary file
        fprintf(tempFile, "%s", line);
    }

    fclose(file);
    fclose(tempFile);

    // Remove the original file
    remove("patient.txt");

    // Rename the temporary file to the original file name
    rename("temp.txt", "patient.txt");

    if (found) {
        printf("\n Patient data deleted successfully from file.\n");
    } else {
        printf("\n Patient with token number %d not found in file.\n", tokenToDelete);
    }
}





void displayMenu() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(50, 500);
    char title[] = "Hospital Operations Prioritization";
    for (int i = 0; i < strlen(title); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);
    }
    glColor3f(1.0, 0.5, 0.5);
    glRasterPos2i(50, 485);
    char line[] = "____________________________";
    for (int i = 0; i < strlen(line); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, line[i]);
    }

    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2i(50, 450);
    char menu[] = "MENU:";
    for (int i = 0; i < strlen(menu); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, menu[i]);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(70, 400);
    char option1[] = "1. Insert a new patient";
    for (int i = 0; i < strlen(option1); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, option1[i]);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(70, 380);
    char option2[] = "2. Delete next patient";
    for (int i = 0; i < strlen(option2); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, option2[i]);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(70, 360);
    char option3[] = "3. Display patient list";
    for (int i = 0; i < strlen(option3); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, option3[i]);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(70, 340);
    char option4[] = "4. Search for a patient";
    for (int i = 0; i < strlen(option4); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, option4[i]);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(70, 320);
    char option5[] = "5. Update patient information";
    for (int i = 0; i < strlen(option5); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, option5[i]);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(70, 300);
    char option6[] = "6. View statistics";
    for (int i = 0; i < strlen(option6); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, option6[i]);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(70, 280);
    char option7[] = "7. Delete Patient data from file";
    for (int i = 0; i < strlen(option7); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, option7[i]);
    }
    
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2i(70, 260);
    char option9[] = "8. Exit";
    for (int i = 0; i < strlen(option9); i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, option9[i]);
    }
    
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(70, 200);
    char option8[] = "Right click on window to display menu";
    for (int i = 0; i < strlen(option8); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, option8[i]);
    }

    
    glColor3f(0.0, 1.0, 0.0);
    switch (selectedOption) {
        case 1:
            glRasterPos2i(50, 400);
            break;
        case 2:
            glRasterPos2i(50, 380);
            break;
        case 3:
            glRasterPos2i(50, 360);
            break;
        case 4:
            glRasterPos2i(50, 340);
            break;
        case 5:
            glRasterPos2i(50, 320);
            break;
        case 6:
            glRasterPos2i(50, 300);
            break;
        case 7:
            glRasterPos2i(50, 280);
            break;
        case 8:
            glRasterPos2i(50, 260);
            break;
    }
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '>');
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            insert();
            break;
        case '2':
            deleteNext();
            break;
        case '3':
            display(0);
            break;
        case '4':
            search();
            break;
        case '5':
            update();
            break;
        case '6':
            statistics();
            break;
        case '7':
            deleteFromFile(0);
            break;
        case '8':
            exit(0);
            break;
    }
}

void menu(int option) {
    selectedOption = option;
    switch (option) {
        case 1:
            insert();
            break;
        case 2:
            deleteNext();
            break;
        case 3:
            display(0);
            break;
        case 4:
            search();
            break;
        case 5:
            update();
            break;
        case 6:
            statistics();
            break;
        case 7:
            {
                int tokenToDelete;
                printf("\n ENTER TOKEN NUMBER of the patient to delete from file: ");
                scanf("%d", &tokenToDelete);
                deleteFromFile(tokenToDelete);
               
                break;
            }
        case 8:
            exit(0);
            break;
    }
}

void createMenu(void) {
    glutCreateMenu(menu);
    glutAddMenuEntry("Insert a new patient", 1);
    glutAddMenuEntry("Delete next patient", 2);
    glutAddMenuEntry("Display patient list", 3);
    glutAddMenuEntry("Search for a patient", 4);
    glutAddMenuEntry("Update patient information", 5);
    glutAddMenuEntry("View statistics", 6);
    glutAddMenuEntry("Delete patient data from file", 7);
    glutAddMenuEntry("Exit", 8);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
    initializeFromFile();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(screenWidth, screenHeight);
    glutCreateWindow("Hospital Operations Prioritization");
    glutDisplayFunc(displayMenu);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    createMenu(); 
    glutMainLoop();
    return 0;
}





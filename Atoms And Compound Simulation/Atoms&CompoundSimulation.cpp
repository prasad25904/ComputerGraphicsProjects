#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define pi 3.142

static GLfloat angle = 0;

static int submenu;
static int submenu2;
static int submenu3;

static int mainmenu;
static int mainmenu2;
static int mainmenu3;

static int value = -1;

void init()
{
    gluOrtho2D(-1300, 1300, -700, 700);
}
void circle(float rad)
{
    glBegin(GL_POINTS);
    glColor3f(2, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}


void circlePos(float rad, float x_offset)
{
    glBegin(GL_POINTS);
    glColor3f(2, 0, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        // Shift the x coordinate by the x_offset value
        glVertex2i(rad * cos(i) + x_offset, rad * sin(i));
    }
    glEnd();
}



void drawString(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *c);
    }
}


void drawStringAN(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Use GLUT_BITMAP_HELVETICA_18 for larger text
    }
}

void drawStringAtomName(float x, float y, float z, char *string)
{
    glColor3f(1.0, 0.0, 0.0); // Set color to red
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Use GLUT_BITMAP_HELVETICA_18 for larger text
    }
}


void drawhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawheadBold(float x, float y, float z, char *string, float scale)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    glPushMatrix();
    glScalef(scale, scale, scale); // Scale the text

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Use the default font size
    }

    glPopMatrix();
}


void drawsubhead(float x, float y, float z, char *string)
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}
void nuc(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}


void nucPos(float rad, float x_offset)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        // Shift the x coordinate by the x_offset value
        glVertex2f(rad * cos(i) + x_offset, rad * sin(i));
    }
    glEnd();
}

void elePos(float rad, float x_offset, float y_offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1,0,0); // Red color
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        // Shift both x and y coordinates by the offsets
        glVertex2f(rad * cos(i) + x_offset, rad * sin(i) + y_offset);
    }
    glEnd();
}

void nucPosYellow(float rad, float x_offset, float y_offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0); // Yellow color
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        // Shift both x and y coordinates by the offsets
        glVertex2f(rad * cos(i) + x_offset, rad * sin(i) + y_offset);
    }
    glEnd();
}
void nucPosBlue(float rad, float x_offset, float y_offset)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1); // Yellow color
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        // Shift both x and y coordinates by the offsets
        glVertex2f(rad * cos(i) + x_offset, rad * sin(i) + y_offset);
    }
    glEnd();
}
void nucPosGreen(float rad, float x_offset, float y_offset)
{
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0); // Green color
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        // Shift both x and y coordinates by the offsets
        glVertex2f(rad * cos(i) + x_offset, rad * sin(i) + y_offset);
    }
    glEnd();
}




void eleright(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad + 20 * cos(i), 20 * sin(i));
    }
    glEnd();
}
void eleleft(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + 20 * cos(i)), 20 * sin(i));
    }
    glEnd();
}
void eletop(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), rad + 20 * sin(i));
    }
    glEnd();
}
void eledown(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), -(rad + 20 * sin(i)));
    }
    glEnd();
}
void eletr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eletl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eledl(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}
void eledr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), -((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}





void eleleft(float rad, float offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + offset + 20 * cos(i)), 20 * sin(i)); // Adjust x-coordinate to draw electrons on the left with an offset
    }
    glEnd();
}

void eleright(float rad, float offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i((rad + offset + 20 * cos(i)), 20 * sin(i)); // Adjust x-coordinate to draw electrons on the right with an offset
    }
    glEnd();
}

void eletop(float rad, float offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), rad + offset + 20 * sin(i)); // Adjust y-coordinate to draw electrons on the top with an offset
    }
    glEnd();
}

void eledown(float rad, float offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), -(rad + offset + 20 * sin(i))); // Adjust y-coordinate to draw electrons on the bottom with an offset
    }
    glEnd();
}

void eletr(float rad, float offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + offset + 20 * cos(i)), ((rad - 175) + offset + 20 * sin(i))); // Adjust x and y coordinates to draw electrons in top-right with an offset
    }
    glEnd();
}

void eletl(float rad, float offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + offset + 20 * cos(i)), ((rad - 175) + offset + 20 * sin(i))); // Adjust x and y coordinates to draw electrons in top-left with an offset
    }
    glEnd();
}

void eledl(float rad, float offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-((rad - 175) + offset + 20 * cos(i)), -((rad - 175) + offset + 20 * sin(i))); // Adjust x and y coordinates to draw electrons in bottom-left with an offset
    }
    glEnd();
}

void eledr(float rad, float offset)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + offset + 20 * cos(i)), -((rad - 175) + offset + 20 * sin(i))); // Adjust x and y coordinates to draw electrons in bottom-right with an offset
    }
    glEnd();
}









void display()
{
    glClearColor(0, 0, 0.1, 0.9);

    if (value == -1)
    {
    	
        char cn[] = "Vishwakarma Institute of Techonolgy, Pune.";
        drawStringAtomName(-400, 630, 0, cn);

        char dn[] = "DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING";
        drawheadBold(-500, 450, 0, dn,2.0);

        char prn[] = "A Mini Project On";
        drawsubhead(-200, 315, 0, prn);
        char pro[] = "ATOM AND COMPOUND SIMULATION";
        drawStringAtomName(-360, 225, 0, pro);

        char pb[] = "PROJECT BY: ";
        drawheadBold(-965, -105, 0, pb,2.0);

        char p1[] = "Prasad Ingle";
        drawhead(-965, -175, 0, p1);
        char p1u[] = "Division -B Batch 2";
        drawsubhead(-965, -210, 0, p1u);

        char gb[] = "Roll no: ";
        drawheadBold(370, -105, 0, gb,2.0);

        char g1[] = "34";
        drawhead(370, -175, 0, g1);
        char d1[] = "12210281";
        drawsubhead(370, -210, 0, d1);

        char in[] = "Left Click the screen and then Press Enter to Continue";
        drawhead(-500, -450, 0, in);
        char in1[] = "Follow following instruction to proceed";
    	drawStringAtomName(-360, -400, 0, in1);
    	char in2[] = "Right Click the screen to get menu.";
    	drawhead(-360, -500, 0, in2);

        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
    if (value != -1 && value !=20)
{
    nuc(200);
    
    
    char n[] = "NUCLEUS";
    drawString(-50, 50, 0, n); // Adjusted position
    char d[] = "(NEUTRON + PROTON)";
    drawString(-100, -40, 0, d); // Adjusted position
    if (value == 0)
    {
        char nu[] = "SELECT THE ELEMENT USING MENU";
        drawhead(-625, 900, 0, nu); // Adjusted position
    }
}
if (value == 1)
{
    char n[] = "HYDROGEN";
    drawhead(-130, 900, 0, n); // Adjusted position
    circle(300); // Adjusted size
    char o[] = "ORBIT";
    drawString(340, 0, 0, o); 
    
    char at[] = "HYDROGEN";
    drawStringAtomName(700, 600, 0, at);
    
    char an[] = "Atomic Number: 1";
    drawString(700, 550, 0, an);
    
    char am[] = "Atomic Mass: 1.0079";
    drawString(700, 490, 0, am);
    
    char ec[] = "Electronic Configuration: 1s1";
    	drawString(700, 440, 0, ec);
    
    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    eleright(300); 
    char e[] = "ELECTRON";
    drawString(400, 0, 0, e); 

    glPopMatrix();
    glutSwapBuffers();
}


    if (value == 2)
    {
        char n[] = "HELIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        char o[] = "ORBIT";
        drawString(340, 0, 0, o);
        
        char at[] = "HELIUM";
    	drawStringAtomName(700, 600, 0, at);
        
        char an[] = "Atomic Number: 2";
    	drawString(700, 550, 0, an);
    
    	char am[] = "Atomic Mass: 4.0026";
    	drawString(700, 490, 0, am);
    	
    	char ec[] = "Electronic Configuration: 1s2";
    	drawString(700, 440, 0, ec);
        
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        char e[] = "ELECTRON";
        drawString(400, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 3)
    {
        char n[] = "LITHIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        char o[] = "ORBIT";
        drawString(570, 0, 0, o);
        
        char at[] = "LITHIUM";
    	drawStringAtomName(700, 600, 0, at);
        
        char an[] = "Atomic Number: 3";
    	drawString(700, 550, 0, an);
    
    	char am[] = "Atomic Mass: 6.941";
    	drawString(700, 490, 0, am);
    	
    	char ec[] = "Electronic Configuration: [He] 2s2";
    	drawString(700, 440, 0, ec);
        
        
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        char e[] = "ELECTRON";
        drawString(0, 520, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 4)
    {
        char n[] = "BERYLLIUM";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        char o[] = "ORBIT";
        drawString(570, 0, 0, o);
        
        char at[] = "BERYLLIUM";
    	drawStringAtomName(700, 600, 0, at);
        
        char an[] = "Atomic Number: 4";
    	drawString(700, 550, 0, an);
    
    	char am[] = "Atomic Mass: 9.0122";
    	drawString(700, 490, 0, am);       
		
		char ec[] = "Electronic Configuration: [He] 2s2 ";
    	drawString(700, 440, 0, ec); 
        
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        char e[] = "ELECTRON";
        drawString(0, 520, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 5)
    {
        char n[] = "BORON";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        char o[] = "ORBIT";
        drawString(570, 0, 0, o);
        
        char at[] = "BORON";
    	drawStringAtomName(700, 600, 0, at);
        
        char an[] = "Atomic Number: 5";
    	drawString(700, 550, 0, an);
    
    	char am[] = "Atomic Mass: 10.811";
    	drawString(700, 490, 0, am);
    	
    	char ec[] = "Electronic Configuration: [He] 2s2 2p1";
    	drawString(700, 440, 0, ec);
    	
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(527);
        char e[] = "ELECTRON";
        drawString(0, 520, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 6)
    {
        char n[] = "CARBON";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        char o[] = "ORBIT";
        drawString(570, 0, 0, o);
        
        char at[] = "CARBON";
    	drawStringAtomName(700, 600, 0, at);
        
        char an[] = "Atomic Number: 6";
    	drawString(700, 550, 0, an);
    
    	char am[] = "Atomic Mass: 12.0107";
    	drawString(700, 490, 0, am);
    	
    	char ec[] = "Electronic Configuration: [He] 2s2 2p2";
    	drawString(700, 440, 0, ec);
    	
        
        
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(527);
        eledl(527);
        char e[] = "ELECTRON";
        drawString(0, 520, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 7)
    {
        char n[] = "NITROGEN";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        char o[] = "ORBIT";
        drawString(570, 0, 0, o);
        
        char at[] = "NITROGEN";
    	drawStringAtomName(700, 600, 0, at);
        
        char an[] = "Atomic Number: 7";
    	drawString(700, 550, 0, an);
    
    	char am[] = "Atomic Mass: 14.0067";
    	drawString(700, 490, 0, am);
    	
    	char ec[] = "Electronic Configuration: [He] 2s2 2p3";
    	drawString(700, 440, 0, ec);
        
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(527);
        eledl(527);
        eletl(527);
        char e[] = "ELECTRON";
        drawString(0, 520, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 8)
    {
        char n[] = "OXYGEN";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        char o[] = "ORBIT";
        drawString(570, 0, 0, o);
        
        char at[] = "OXYGEN";
    	drawStringAtomName(700, 600, 0, at);
        
        char an[] = "Atomic Number: 8";
    	drawString(700, 550, 0, an);
    
    	char am[] = "Atomic Mass: 15.9994";
    	drawString(700, 490, 0, am);
    	
    	char ec[] = "Electronic Configuration: [He] 2s2 2p4";
    	drawString(700, 440, 0, ec);
    	
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(527);
        eledl(527);
        eletl(527);
        eledr(527);
        char e[] = "ELECTRON";
        drawString(0, 520, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 9)
    {
        char n[] = "FLUORINE";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        char o[] = "ORBIT";
        drawString(570, 0, 0, o);
        
        char at[] = "FLUORINE";
    	drawStringAtomName(700, 600, 0, at);
        
        char an[] = "Atomic Number: 9";
    	drawString(700, 550, 0, an);
    
    	char am[] = "Atomic Mass: 18.9984";
    	drawString(700, 490, 0, am);
    	
    	char ec[] = "Electronic Configuration: [He] 2s2 2p5";
    	drawString(700, 440, 0, ec);
    	
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(527);
        eledl(527);
        eletl(527);
        eledr(527);
        eleleft(500);
        char e[] = "ELECTRON";
        drawString(0, 520, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 10)
    {
        char n[] = "NEON";
        drawhead(-100, 900, 0, n);
        circle(300);
        circle(500);
        char o[] = "ORBIT";
        drawString(570, 0, 0, o);
        
        char at[] = "NEON";
    	drawStringAtomName(700, 600, 0, at);
        
        char an[] = "Atomic Number: 10";
    	drawString(700, 550, 0, an);
    
    	char am[] = "Atomic Mass: 20.1797";
    	drawString(700, 490, 0, am);
    	
    	char ec[] = "Electronic Configuration: [He] 2s2 2p6";
    	drawString(700, 440, 0, ec);
    	
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(300);
        eleleft(300);
        eletop(500);
        eledown(500);
        eletr(527);
        eledl(527);
        eletl(527);
        eledr(527);
        eleleft(500);
        eleright(500);
        char e[] = "ELECTRON";
        drawString(0, 520, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    
    

if (value == 17) // Handle Carbon Dioxide
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Carbon and Oxygen molecules
    nucPos(200, 0);
    char carbon[] = "Carbon";
    drawStringAN(-80, 0, 0, carbon);
    circlePos(300, 0);
    circlePos(400, 0);
    
    nucPos(220, -800);
    char oxygen1[] = "Oxygen";
    drawStringAN(-850, 0, 0, oxygen1);
    circlePos(300, -800);
    circlePos(450, -800);
    
    nucPos(220, 800);
    drawStringAN(710, 0, 0, oxygen1);
    circlePos(300, 800);
    circlePos(450, 800);

    // Rotate and draw bonds between atoms
    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    eleright(300);
    eleleft(300);
    eletop(400);
    eledown(400);
    eletr(450);
    eledl(450);
    glPopMatrix();
    
    // Define the coordinates of the Oxygen atom
    float oxygenX = 787;
    float oxygenY = -15;

    // Draw bonds revolving around the Oxygen atom
    glPushMatrix();
    glTranslatef(oxygenX, oxygenY, 0);  // Translate to the position of Oxygen atom
    glRotatef(angle, 0, 0, 1);           // Rotate around the Oxygen atom
    eleright(300);                       // Draw bonds or elements
    eleleft(300);
    eletop(465);
    eledown(465);
    eletr(480);
    eledl(470);
    eletl(470);
    glPopMatrix();

    // Draw bonds revolving around the Oxygen atom
    glPushMatrix();
    glTranslatef(-765, -15, 0);  // Translate to the position of Oxygen atom
    glRotatef(angle, 0, 0, 1);           // Rotate around the Oxygen atom
    eleright(300);                       // Draw bonds or elements
    eleleft(300);
    eletop(465);
    eledown(465);
    eletr(480);
    eledl(470);
    eletl(470);
    glPopMatrix();


    // Display relevant information for Carbon Dioxide
    char compound_name[] = "Carbon Dioxide";
    drawhead(-100, 900, 0, compound_name);
    
    char atomic_name[] = "Carbon Dioxide";
    drawStringAtomName(700, 600, 0, atomic_name);
    
    char chemical_formula[] = "CO2 : O=C=O"; 
    drawString(700, 550, 0, chemical_formula);
    
    char molar_mass[] = "Molar Mass: 44.009 g·mol-1"; 
    drawString(700, 490, 0, molar_mass);
    
    char reaction[] = "Reaction : 2 HCl(aq) + Na2CO3(aq) --> 2 NaCl(aq) + H2O(l) + CO2(g) "; 
    drawStringAN(-650, 550, 0, reaction);
    
    glutSwapBuffers(); 
}



    

if (value == 18) // Handle Carbon Dioxide
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Carbon and Oxygen molecules
    nucPos(200, 0);
    char oxygen1[] = "Oxygen";
    drawStringAN(-80, 0, 0, oxygen1);
    circlePos(300, 0);
    circlePos(400, 0);
    
    nucPos(170, -700);
    char hydrogen[] = "Hydrogen";
    drawStringAN(-760, 0, 0, hydrogen);
    circlePos(300, -700);
    
    
    nucPos(170, 700);
    drawStringAN(640, 0, 0, hydrogen);
    circlePos(300, 700);
    

    // Rotate and draw bonds between atoms
    glPushMatrix();
    glRotatef(angle, 0, 0, 1);
    eleright(300);
    eleleft(300);
    eletop(400);
    eledown(400);
    eletr(450);
    eledl(450);
    eledl(450);
    eletl(450);
    glPopMatrix();
    
    // Define the coordinates of the Oxygen atom
    float oxygenX = 700;
    float oxygenY = -15;

    // Draw bonds revolving around the Oxygen atom
    glPushMatrix();
    glTranslatef(oxygenX, oxygenY, 0);  // Translate to the position of Oxygen atom
    glRotatef(angle, 0, 0, 1);           // Rotate around the Oxygen atom
    eleright(300);                       // Draw bonds or elements
    
    glPopMatrix();

    // Draw bonds revolving around the Oxygen atom
    glPushMatrix();
    glTranslatef(-765, -15, 0);  // Translate to the position of Oxygen atom
    glRotatef(angle, 0, 0, 1);           // Rotate around the Oxygen atom
    eleright(300);                       // Draw bonds or elements
    
    glPopMatrix();


    // Display relevant information for Carbon Dioxide
    char compound_name[] = "Hydrogen oxide";
    drawhead(-100, 900, 0, compound_name);
    
    char atomic_name[] = "Hydrogen oxide";
    drawStringAtomName(700, 600, 0, atomic_name);
    
    char chemical_formula[] = "H2O : H=O=H "; 
    drawString(700, 550, 0, chemical_formula);
    
    char molar_mass[] = "Molar Mass: 18.01528(33) g/mol"; 
    drawString(700, 490, 0, molar_mass);
    
    char reaction[] = "Reaction : O2 + 4 H3O+ + 4 e- --> 6 H2O "; 
    drawStringAN(-550, 550, 0, reaction);
    
    glutSwapBuffers(); 
}


if (value == 19) // Handle Oxygen molecule
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Display relevant information for Oxygen molecule
    char compound_name[] = "Oxygen";
    drawhead(-100, 900, 0, compound_name);

    char atomic_name[] = "Oxygen";
    drawStringAtomName(750, 600, 0, atomic_name);

    char chemical_formula[] = "O2 : O=O ";
    drawString(750, 550, 0, chemical_formula);

    char molar_mass[] = "Molar Mass: 32 g/mol";
    drawString(750, 490, 0, molar_mass);

    char reaction[] = "Reaction : 2 H2O --> O2 + 4 H+ + 4 e-";
    drawStringAN(-400, 550, 0, reaction);

    // Draw Oxygen molecules
    nucPos(200, -450);
    char oxygen[] = "Oxygen";
    drawStringAN(-510, 0, 0, oxygen);
    circlePos(350, -450);
    circlePos(500, -450);
    
    nucPos(200, 450);
    drawStringAN(460, 0, 0, oxygen);
    circlePos(350, 450); //300
    circlePos(500, 450);  //400

  

    // Define the coordinates of the Oxygen atoms
    float oxygenX1 = 437;
    float oxygenY1 = -27;
    float oxygenX2 = -465;
    float oxygenY2 = -27;

    // Draw bonds revolving around the Oxygen atoms
    glPushMatrix();
    glTranslatef(oxygenX1, oxygenY1, 0);
        glRotatef(angle, 0, 0, 1);
        
        eleright(350);
        eleleft(350);
        eletop(550);
        eledown(550);
        eletr(550);
        eledl(550);
        eletl(550);
        eledr(550);
        char e[] = "ELECTRON";
        drawString(0, 520, 0, e);
    glPopMatrix();
        

	glPushMatrix();
	glTranslatef(oxygenX2, oxygenY2, 0);
        glRotatef(angle, 0, 0, 1);
        
        eleright(350);
        eleleft(350);
        eletop(550);
        eledown(550);
        eletr(557);
        eledl(557);
        eletl(557);
        eledr(557);
        char e2[] = "ELECTRON";
        drawString(0, 520, 0, e2);
        glPopMatrix();


    

    glutSwapBuffers();
}

if(value == 20){
	char uranium[]="URANIUM-235";
	nucPos(150,-700);
	//nucPos(90,-100);
	elePos(20,-1100,0);

    drawStringAN(-820, 0, 0, uranium);
    
    
    char reaction[] = "Chain Reaction : (1) 0n + (235) 92U -> (141) 56Ba + (92) 36Kr + 3 (1) 0n";
    drawStringAN(-800, 550, 0, reaction);
    
    elePos(20,-60,150);
	nucPosYellow(90,-250,150);
    elePos(20,-60,0);
    nucPosGreen(120,-250,-150);
    elePos(20,-60,-150);
    
    char plus[]= "+";
    char arrow[]= " -> ";
    
    drawStringAN(-320, 0, 0, plus);
    drawStringAN(-1200,-10, 0, arrow);
    
    drawStringAN(-150,150, 0, arrow);
    drawStringAN(-150,0, 0, arrow);
    drawStringAN(-150,-150, 0, arrow);
    
    drawStringAN(0,150, 0, arrow);
    //drawStringAN(0,0, 0, arrow);
    drawStringAN(0,-150, 0, arrow);
    
    char neutron[] = "Neutron";
    drawStringAN(-1200,30, 0, neutron);
    
    char barium[]="BARIUM-144";
    drawStringAN(-320,-310, 0, barium);
    
    char krypton[]="KRYPTON-89";
    drawStringAN(-320,260, 0, krypton);
    
	char uranium2[]="URANIUM-235";
	nucPosBlue(150,250,200);
	drawStringAN(130,200, 0, uranium2);
	
	elePos(20,950,560);
	nucPosYellow(90,700,500);
    elePos(20,950,410);
    nucPosGreen(120,700,250);
    elePos(20,950,250);
    
    drawStringAN(820,560, 0, arrow);
    drawStringAN(820,410, 0, arrow);
    drawStringAN(820,250, 0, arrow);
	
	char uranium3[]="URANIUM-235";
	nucPosBlue(150,250,-200);
	drawStringAN(130,-200, 0, uranium3);
	
	elePos(20,950,-560);
	nucPosYellow(90,700,-250);
    elePos(20,950,-410);
    nucPosGreen(120,700,-500);
    elePos(20,950,-250);
    
    
    drawStringAN(820,-560, 0, arrow);
    drawStringAN(820,-410, 0, arrow);
    drawStringAN(820,-250, 0, arrow);
    
}




    glutSwapBuffers();
}
void rotate()
{
    angle = angle + 1.0;
    if (angle > 360)
    {
        angle = angle - 360;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}
void mouseControl(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
            glutIdleFunc(rotate);
        break;
    default:
        break;
    }
}
void keyboard(unsigned char key, int x, int y)
{
    if (key == 13)
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    else if (key == 's')
    {
        glutIdleFunc(NULL);
    }
    else if (key == 32)
    {
        glutIdleFunc(rotate);
    }
    else if (key == 'q' || key == 'Q')
    {
        exit(0);
    }
    else if (key == 27)
    {
        glutReshapeWindow(700, 700);
    }
}
void fkey(int key, int x, int y)
{

    if (key == GLUT_KEY_F10)
    {
        glutReshapeWindow(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
    }
}
void menu(int option)
{
    if (option == 15)
    {
        exit(0);
    }
    else if (option == 11)
    {
        glutIdleFunc(rotate);
    }
    else if (option == 12)
    {
        glutIdleFunc(NULL);
    }
    else if(option==14){
        value=-1;
    }
    else
    {
        value = option;
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glutPostRedisplay();
}
void createMenu(void)
{
  
    submenu = glutCreateMenu(menu);
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERILIUM", 4);
    glutAddMenuEntry("BORON", 5);
    glutAddMenuEntry("CARBON", 6);
    glutAddMenuEntry("NITROGEN", 7);
    glutAddMenuEntry("OXYGEN", 8);
    glutAddMenuEntry("FLUORINE", 9);
    glutAddMenuEntry("NEON", 10);
    
    
    submenu2 = glutCreateMenu(menu);
    glutAddMenuEntry("CO2[Carbon Dioxide]", 17);
    glutAddMenuEntry("H2O[Water]", 18);
    glutAddMenuEntry("O2[DiOxygen]", 19);
    
    submenu3=glutCreateMenu(menu);
    glutAddMenuEntry("URANIUM",20);
    
    mainmenu = glutCreateMenu(menu);
    glutAddSubMenu("SELECT THE ELEMENT", submenu); 
    glutAddSubMenu("SELECT THE COMPOUND", submenu2); 
    glutAddSubMenu("SELECT THE RADIOACTIVE ELEMENT CHAIN REACTION",submenu3);
    
    glutAddMenuEntry("START SIMULATION", 11);
    glutAddMenuEntry("STOP SIMULATION", 12);
    glutAddMenuEntry("GOTO HOME SCREEN",14);
    glutAddMenuEntry("EXIT", 13);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}





int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(70, 70);
    glutInitWindowSize(1300, 700);
    glutCreateWindow("ATOM SIMULATION");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseControl);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(fkey);
    createMenu();
    glutMainLoop();
    return 0;
}
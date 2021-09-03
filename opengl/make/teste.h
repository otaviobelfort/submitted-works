  /* Cubo 1 */
  glPushMatrix();
  glColor3i(1.0,0.0,0.0);
  glTranslatef (2.0, -2.0, -1.0);
  glTranslatef (0.0, 4.0, 0.0);
  glScalef (3.0, 2.0, 5.0);
  glutWireCube (1.0);
  glPopMatrix();


// /* Cubo 2 */
glPushMatrix();
glRotatef (25.0, 0.0, 0.0, 1.0);
glTranslatef (2.0, 0.0, 0.0);
glScalef (2.0, 1.0, 4.0);
glutWireCube (1.0);
glPopMatrix();

// /* Cubo 3 */
glPushMatrix();
glTranslatef (0.0, 2.0, 0.0);
glScalef (2.0, 1.0, 4.0);
glutWireCube (1.0);
glPopMatrix();

// /* Cubo 4 */
glPushMatrix();
glTranslatef (0.0, -2.0, 0.0);
glScalef (2.0, 1.0, 4.0);
glutWireCube (1.0);
glPopMatrix();
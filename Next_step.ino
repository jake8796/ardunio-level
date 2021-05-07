int r1 = 2;
int r2 = 3;
int r3 = 4;
int r4 = 5;
int r5 = 6;
int r6 = 7;
int r7 = 8;
int r8 = 9;
int c1 = 10;
int c2 = 11;
int c3 = 12;
int c4 = 13;
int c5 = A2;
int c6 = A3;
int c7 = A4;
int c8 = A5;
int xout=A0;
int yout=A1;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  pinMode(r5, OUTPUT);
  pinMode(r6, OUTPUT);
  pinMode(r7, OUTPUT);
  pinMode(r8, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);
  pinMode(c3, OUTPUT);
  pinMode(c4, OUTPUT);
  pinMode(c5, OUTPUT);
  pinMode(c6, OUTPUT);
  pinMode(c7, OUTPUT);
  pinMode(c8, OUTPUT);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  digitalWrite(r4,HIGH);
  digitalWrite(r5,HIGH);
  digitalWrite(r6,HIGH);
  digitalWrite(r7,HIGH);
  digitalWrite(r8,HIGH);
  digitalWrite(c1,LOW);
  digitalWrite(c2,LOW);
  digitalWrite(c3,LOW);
  digitalWrite(c4,LOW);
  digitalWrite(c5,LOW);
  digitalWrite(c6,LOW);
  digitalWrite(c7,LOW);
  digitalWrite(c8,LOW);
//Accelerameter set-up
  pinMode(xout, INPUT);
  pinMode(yout, INPUT);
}
// Functions
void cycleLED(int row,int col){
  digitalWrite(row,LOW);
  digitalWrite(col,HIGH);
  delay(1);
  digitalWrite(row,HIGH);
  digitalWrite(col,LOW);
 }
void blockOn(int row1, int col1, int row2, int col2){
  cycleLED(row1, col1);
  cycleLED(row1, col2);
  cycleLED(row2, col1);
  cycleLED(row2, col2);
}
class Block {
  int row[8] = {r1,r2,r3,r4,r5,r6,r7,r8};
  int col[8] = {c1,c2,c3,c4,c5,c6,c7,c8};
  public:
  int xcor1;
  int xcor2;
  int ycor1;
  int ycor2;
  
  void loop(){
    blockOn(row[xcor1],col[ycor1],row[xcor2],col[ycor2]);
  }
  void Block::changeCol(int xval){
  if(xval <316){
    ycor1 = 0;
    ycor2 = 1;   
  }
  else if(xval >= 316 && xval < 323){
    ycor1 = 1;
    ycor2 = 2;
  }
  else if(xval >= 323 && xval < 330){
    ycor1 = 2;
    ycor2 = 3;
  }
  else if(xval >= 330 && xval < 338){
    ycor1 = 3;
    ycor2 = 4;
  }
  else if(xval >= 338 && xval < 345){
    ycor1 = 4;
    ycor2 = 5; 
  }
  else if(xval >=345 && xval < 352){
    ycor1 = 5;
    ycor2 = 6;
  }
  else if(xval >= 352){
    ycor1 = 6;
    ycor2 = 7;
  } 
  }
  void Block::changeRow(int yval){
  if(yval < 316){
    xcor1 = 7;
    xcor2 = 6;   
  }
  else if(yval >= 316 && yval < 323){
    xcor1 = 6;
    xcor2 = 5;
  }
  else if(yval >= 323 && yval < 330){
    xcor1 = 5;
    xcor2 = 4;
  }
  else if(yval >= 330 && yval < 338){
    xcor1 = 4;
    xcor2 = 3;
  }
  else if(yval >= 338 && yval < 345){
    xcor1 = 3;
    xcor2 = 2; 
  }
  else if(yval >= 345 && yval < 352){
    xcor1 = 2;
    xcor2 = 1;
  }
  else if(yval >= 352){
    xcor1 = 1;
    xcor2 = 0;
  } 
  }
};


Block block;
void loop() {
  
  int xval = analogRead(xout);
  delay(1);  
 
  int yval = analogRead(yout);
  delay(1);

  block.changeRow(yval);
  block.changeCol(xval);
  block.loop();
}

int trig1=3; 
int echo1=4;
int lm1 = 5;
int lm2 = 6;
int rm1 = 9;
int rm2 = 10;


void setup()
{
  Serial.begin(9600);
  pinMode(trig1,OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
}

int dis;
void loop()
{
  dis = check_dist(trig1,echo1);
  Serial.print ("Distance = ");
  Serial.print (dis);         
  Serial.print (" cm");
  Serial.write(10);
  forward();
  if(dis <= 40)
  {
    right();
  }

}

void forward()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}

void stopt()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}
void right()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
}

void left()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
}


int check_dist(int trig,int echo)
{
  digitalWrite(trig,LOW);
  delayMicroseconds(5);        
  digitalWrite(trig,HIGH);  
  delayMicroseconds(10);      
  digitalWrite(trig,LOW); 
  int dist;
  dist=pulseIn(echo,HIGH);
  dist = dist/58;           
  
   
  return dist;
}
  

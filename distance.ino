
int dist;
int dist1;
int strength;
int check;
int i;
int uart[9];
const int HEADER=0x59;
void setup(){
  Serial.begin(9600);
  Serial1.begin(115200);
}


void loop() 
{
  Serial.print(".");
    if(Serial1.read()==HEADER)
    
    {
        uart[0]=HEADER;
        if(Serial1.read()==HEADER)
        {
            uart[1]=HEADER;
            for(i=2;i<9;i++)
            {
                uart[i]=Serial1.read();
            }
            check=uart[0]+uart[1]+uart[2]+uart[3]+uart[4]+uart[5]+uart[6]+uart[7];
            if(uart[8]==(check&0xff))   
            {
                dist=uart[2]+uart[3];
                //dist1 = dist / 100;
                strength=uart[4]+uart[5];
                Serial.print("Distance = ");
                Serial.print(dist);
                Serial.print("cm");
                Serial.print('\n');
                
                //Serial.print('\t');
                //Serial.print("strength = ");
                //Serial.print(strength);
                //Serial.print('\n');
            }
        }
    }
}

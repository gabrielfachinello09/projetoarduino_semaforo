//Declarando os pinos
const int trig = 9; //Constante do tipo primitivo int, recebe o nome trig no pino 9.
const int echo = 10;

//Void que inicializa os pinos e demais componenentes
void setup () {
  pinMode(trig,OUTPUT); //Envia o sinal (aaaa)
  pinMode(echo,INPUT); //Recebe o sinal (ouvindo o eco do grito)
  Serial.begin(9600); //Inicializa o monitor serial (9600 é a vel. de comunicação)
}

//Void que se repete infinitamente
void loop (){ //Função que não possui retorno, apenas execução.
  digitalWrite(trig,LOW); //LOW: Pino desligado ; HIGH: Pino ligado.
  delayMicroseconds(10);
 
  digitalWrite(trig,HIGH); //Nesse momento, o sensor emite sinal.
  delayMicroseconds(10); //Passam-se 10 microsegundos.
  digitalWrite(trig,LOW); //Sensor para de enviar o sinal
 
  int tempo = pulseIn(echo,HIGH); //Descobre a variação de tempo (delta t)
  long distancia = 0.0343 * tempo /2 ;
  Serial.print("O valor da distancia:  ");
  Serial.println(distancia);
   
  delay(500);
}

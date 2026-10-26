typedef struct GPIO
 {
	int pin;
	int state;
	float voltage;

}LED;

void setgpiopin_state(LED,int);
void initialize_gpiocpin(LED);

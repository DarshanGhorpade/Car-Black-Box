#ifndef CAR_BLACK_BOX_H
#define	CAR_BLACK_BOX_H
void display_dash_board(char event[], unsigned  char speed);
void log_car_event(char event[], unsigned char speed);
void clear_screen(void);
char login(unsigned char key,unsigned char reset_flag);
char login_menu(unsigned char key,unsigned char reset_flag);
void view_log(unsigned char key,unsigned char reset_flag);
char clear_log(unsigned char reset_flag);
char change_password(unsigned char key,unsigned char reset_flag);

#endif
#include <stdio.h>
 
int masu[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int player = 0;
int win = 0;
 
void print_masu(void);  //�֐��v���g�^�C�v�錾
int check_win(void);    //�֐��v���g�^�C�v�錾
 
int main(void)
{
    int i = 0;
    int put = 0;
    int yoko = 0;   //�s - ���R
    int tate = 0;   //�� - �^�e
 
    printf("\n [ ���~�Q�[�� ] \n");
 
    for( i = 0; i<9 && win==0; i++){
        print_masu();   //�}�X�̕\��
 
        player = i%2 + 1;   //�v���C���[�ԍ�
 
        do{
            printf("���Ȃ��̃V���{���}�[�N:[ %c ]\n"
                   "�v���C���[%d�̃^�[�� / �}�X�ԍ������:",(player ==2)?'X':'0', player);
 
            while(1){
                if (scanf("%d", &put) != 1){
                    scanf("%*s");
                    if(feof(stdin)){
                    /* �G���[���� */
                    }
                    continue;
                }
                if (put<10 || put>0){
                    break;
                }
            }
 
            yoko = (put-1)/3;   //�s���W�����o��
            tate = (put-1)%3;   //����W�����o��
 
            if(masu[yoko][tate]>'9')
                printf("%c����������������܂���B�ēx���͂��Ă�������\n",masu[yoko][tate]);
 
        }while(put<0 || put>9 || masu[yoko][tate]>'9');
 
        //�V���{���̑}��
        masu[yoko][tate] = (player == 2) ? 'X' : 'O';
 
        check_win();    //���������̃`�F�b�N
    }
 
    //���U���g - �{�[�h�̕\��
    printf("\n �����ʔ��\���@\n");
    print_masu();   //�}�X�̕\��
 
    //���U���g - ���
    if(win == 0)    //win=0�Ȃ��������
        printf("\a���҈�������\n");
    else
        printf("\a\a����:�v���C���[ %d\n", win);
 
    return(0);
}
//�֐�1
//�@�\�F3x3�̃}�X�ڂ�printf�ŏo��
//�����F�Ȃ�
//�߂�l�F�Ȃ�

void print_masu(void){
    printf("��������������\n");
    printf("��%2c��%2c��%2c��\n",masu[0][0],masu[0][1],masu[0][2]);
    printf("��������������\n");
    printf("��%2c��%2c��%2c��\n",masu[1][0],masu[1][1],masu[1][2]);
    printf("��������������\n");
    printf("��%2c��%2c��%2c��\n",masu[2][0],masu[2][1],masu[2][2]);
    printf("��������������\n\n");
}
//�}�X�̕\���֐�

 
//�֐�2

//�@�\�F�Ίp���E�c����3�A�𒲂ׂ�
//�����F�Ȃ�
//�߂�l�Fwin=(0:�ǂ�����܂�����łȂ��A1:�����R�A�A2:�~���R�A)

int check_win(void){
    int line = 0;
 
    //���������̃`�F�b�N - �Ίp��
    if((masu[0][0] == masu[1][1] && masu[0][0] == masu[2][2]) ||
    (masu[0][2] == masu[1][1] && masu[0][2] == masu[2][0]))
        win = player;       //���������𖞂����Ƃ���win��player����
    else
    //���������̃`�F�b�N - �c���̃��C��
    for(line = 0; line <= 2; line ++)
    if((masu[line][0] == masu[line][1] && masu[line][0] == masu[line][2])||
      (masu[0][line] == masu[1][line] && masu[0][line] == masu[2][line]))
        win = player;   //���������𖞂����Ƃ���win��player����
    return(win);
}
//3�A�������`�F�b�N����֐�

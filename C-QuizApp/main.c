#include <stdio.h>
#include <stdbool.h>

#define MSG_LEN 50
#define Quiz_Len 4

typedef struct quiz
{
    char quiz_msg[Quiz_Len][MSG_LEN];
} Quiz;

typedef struct quiz_class
{
    char announce[MSG_LEN];
    int correct;
    Quiz quiz;
} Quiz_Class;

bool isCorrect(int x, int y)
{
    if(x == y){
        printf("%s\n","正解！");
        return true;
    }
    printf("%s\n","不正解！");
    return false;
}

void countup(int *counter, bool isCorrect)
{
    if(isCorrect)
        *counter += 1;
}

void routine(int quiz_count,const Quiz_Class qc[],int *correct_count)
{
    int cor;
    int i;
    for(i = 0; i<quiz_count; i++){
        printf("%s\n",qc[i].announce);
        int ii;
        for (ii = 0; ii < quiz_count; ii++) { printf("%s\n", qc[i].quiz.quiz_msg[ii]); }
        scanf("%d", &cor);
        countup(correct_count, isCorrect(cor,qc[i].correct));
    }
}

int main()
{

    int correct_count;

    Quiz firstQuiz = {"フランス","アイスランド","イギリス","日本"};
    Quiz_Class firstQuizClass = {"世界で一番物価が高い国は？", 2,firstQuiz};
    Quiz secondQuiz = {"アメリカ","ロシア","中国","カナダ"};
    Quiz_Class secondQuizClass = {"世界で一番面積の広い国は？",2,secondQuiz};
    Quiz thirdQuiz = {"インド","コンゴ","アンゴラ","ギニア"};
    Quiz_Class thirdQuizClass = {"この中で国の中にある国は？",3,thirdQuiz};
    Quiz forthQuiz = {"コスタリカ","ニカラグア","グアテマラ","ベネズエラ"};
    Quiz_Class forthQUizClass = {"中米ではない国は？",4,forthQuiz};

    Quiz_Class app_quiz_list[Quiz_Len] = {firstQuizClass,secondQuizClass,thirdQuizClass,forthQUizClass};
    routine(Quiz_Len,app_quiz_list,&correct_count);

    printf("%s\n","終了！");
    printf("%s %d %s", "正解数は",correct_count, "です！");
    return 0;
}

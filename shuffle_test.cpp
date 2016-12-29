#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void init_card(std::vector<int>& cardlist)
{
    std::vector<int> handlist1;
    std::vector<int> handlist2;
    std::vector<int> handlist3;
    std::vector<int> handlist4;
    for (int i = 0; i < 13; i++)
    {
        handlist1.push_back(cardlist[i*4+0]);
        handlist2.push_back(cardlist[i*4+1]);
        handlist3.push_back(cardlist[i*4+2]);
        handlist4.push_back(cardlist[i*4+3]);
    }
    std::sort(handlist1.begin(), handlist1.end());
    std::sort(handlist2.begin(), handlist2.end());
    std::sort(handlist3.begin(), handlist3.end());
    std::sort(handlist4.begin(), handlist4.end());
    printf("1: "); 
    for (int k = 0; k < handlist1.size(); k++)
    {
        printf("%4d", handlist1[k]);
    }
    printf("\n");
    printf("2: "); 
    for (int k = 0; k < handlist2.size(); k++)
    {
        printf("%4d", handlist2[k]);
    }
    printf("\n");
    printf("3: "); 
    for (int k = 0; k < handlist3.size(); k++)
    {
        printf("%4d", handlist3[k]);
    }
    printf("\n");
    printf("4: "); 
    for (int k = 0; k < handlist4.size(); k++)
    {
        printf("%4d", handlist4[k]);
    }
    printf("\n");
    printf("**********************************\n");
}

void init_card1(std::vector<int>& cardlist)
{
    std::vector<int> handlist1;
    std::vector<int> handlist2;
    std::vector<int> handlist3;
    std::vector<int> handlist4;
    int i = 0;
    for ( ; i < 3; i++)
    {
        handlist1.push_back(cardlist[0+16*i]);
        handlist1.push_back(cardlist[1+16*i]);
        handlist1.push_back(cardlist[2+16*i]);
        handlist1.push_back(cardlist[3+16*i]);
        handlist2.push_back(cardlist[4+16*i]);
        handlist2.push_back(cardlist[5+16*i]);
        handlist2.push_back(cardlist[6+16*i]);
        handlist2.push_back(cardlist[7+16*i]);
        handlist3.push_back(cardlist[8+16*i]);
        handlist3.push_back(cardlist[9+16*i]);
        handlist3.push_back(cardlist[10+16*i]);
        handlist3.push_back(cardlist[11+16*i]);
        handlist4.push_back(cardlist[12+16*i]);
        handlist4.push_back(cardlist[13+16*i]);
        handlist4.push_back(cardlist[14+16*i]);
        handlist4.push_back(cardlist[15+16*i]);
    }
    handlist1.push_back(cardlist[i*16+0]);
    handlist2.push_back(cardlist[i*16+1]);
    handlist3.push_back(cardlist[i*16+2]);
    handlist4.push_back(cardlist[i*16+3]);
    std::sort(handlist1.begin(), handlist1.end());
    std::sort(handlist2.begin(), handlist2.end());
    std::sort(handlist3.begin(), handlist3.end());
    std::sort(handlist4.begin(), handlist4.end());
    printf("1: "); 
    for (int k = 0; k < handlist1.size(); k++)
    {
        printf("%4d", handlist1[k]);
    }
    printf("\n");
    printf("2: "); 
    for (int k = 0; k < handlist2.size(); k++)
    {
        printf("%4d", handlist2[k]);
    }
    printf("\n");
    printf("3: "); 
    for (int k = 0; k < handlist3.size(); k++)
    {
        printf("%4d", handlist3[k]);
    }
    printf("\n");
    printf("4: "); 
    for (int k = 0; k < handlist4.size(); k++)
    {
        printf("%4d", handlist4[k]);
    }
    printf("\n");
    printf("**********************************\n");
}


void shuffle_test(int count)
{
    std::vector<int> cardlist;
    for (int i = 1; i < 10; i ++)
    {
        cardlist.push_back(i);
        cardlist.push_back(i);
        cardlist.push_back(i);
        cardlist.push_back(i);
    }
    for (int i = 11; i < 20; i ++)
    {
        cardlist.push_back(i);
        cardlist.push_back(i);
        cardlist.push_back(i);
        cardlist.push_back(i);
    }
    for (int i = 21; i < 30; i ++)
    {
        cardlist.push_back(i);
        cardlist.push_back(i);
        cardlist.push_back(i);
        cardlist.push_back(i);
    }
    cardlist.push_back(0);
    cardlist.push_back(0);
    cardlist.push_back(0);
    cardlist.push_back(0);

    int result[112][30];
    for (int i = 0; i < 112; i++)
    {
        memset(result[i], 0, 30*sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++)
    {
        //sleep(5);
        std::vector<int> testlist;
        testlist.assign(cardlist.begin(), cardlist.end());
        random_shuffle(testlist.begin(), testlist.end());

        for (int j = 0; j < testlist.size(); j++)
        {
            result[j][testlist[j]]++;
        }
       
        init_card(testlist);
        init_card1(testlist);
        std::vector<int> handlist1;
        handlist1.assign(testlist.begin(), testlist.begin()+13);
        std::sort(handlist1.begin(), handlist1.end());
        std::vector<int> handlist2;
        handlist2.assign(testlist.begin()+13, testlist.begin()+26);
        std::sort(handlist2.begin(), handlist2.end());
        std::vector<int> handlist3;
        handlist3.assign(testlist.begin()+26, testlist.begin()+39);
        std::sort(handlist3.begin(), handlist3.end());
        std::vector<int> handlist4;
        handlist4.assign(testlist.begin()+39, testlist.begin()+52);
        std::sort(handlist4.begin(), handlist4.end());
        printf("1: "); 
        for (int k = 0; k < handlist1.size(); k++)
        {
            printf("%4d", handlist1[k]);
        }
        printf("\n");
        printf("2: "); 
        for (int k = 0; k < handlist2.size(); k++)
        {
            printf("%4d", handlist2[k]);
        }
        printf("\n");
        printf("3: "); 
        for (int k = 0; k < handlist3.size(); k++)
        {
            printf("%4d", handlist3[k]);
        }
        printf("\n");
        printf("4: "); 
        for (int k = 0; k < handlist4.size(); k++)
        {
            printf("%4d", handlist4[k]);
        }
        printf("\n");
        printf("==========================================================\n");
    }

    /*
    for (int i = 0; i < 112; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < 30; j++)
        {
            if (j == 10 || j == 20)
                continue;
            printf("%7d", result[i][j]);
        }
        printf("\n");
    }
    */
}

int main()
{
    //shuffle_test(1000000);
    shuffle_test(1000);

    return 0;
}

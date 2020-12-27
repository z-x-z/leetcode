#include"WordDict.h"
class DictClient
{
private:
    WordDict dict;
public:

    DictClient(ifstream& ifs)
    :dict(ifs)
    {}

    void listAllWord() // 1
    {
        dict.listDictWords();
    }

    void countWord() // 2
    {
        dict.printDictCount();
    }

    void searchBySepll(string& spellStr) // 3
    {
        dict.spellSearch(spellStr);
    }

    void searchByMeaning(string& meaningStr) // 4
    {
        dict.meaningSearch(meaningStr);
    }

    void listWordsOutFrequency(double frequency)
    {
        dict.listWordsOutFrequency(frequency);
    }

    void run()
    {
        string promptStr =
        "***********************************************************************\n"
        "*****    Please input number 1 ~ 6 to use following function:     *****\n"
        "1 ~ List all the word in the dict.\n"
        "2 ~ Count the total word and different word property nums.\n"
        "3 ~ Search word accounding to its spell.\n"
        "4 ~ Search word accounding to its chinese meaning.\n"
        "5 ~ List all the word which frequency bigger than the given frequency.\n"
        "6 ~ Exit.\n"
        "***********************************************************************\n";
        int operId;
        string spellStr, meaningStr;
        double frequency;
        while (true)
        {
            printf("%s", promptStr.c_str());
            cin>>operId;
            printf("\n");
            switch (operId)
            {
                case 1:
                    printf("All words are as follows:\n");
                    listAllWord();
                    break;
                case 2:
                    countWord();
                    break;
                case 3:
                    printf("Input word spell:\n");
                    cin>> spellStr;
                    searchBySepll(spellStr);
                    break;
                case 4:
                    printf("Input word meaning (chinese):\n");
                    cin>> meaningStr;
                    searchByMeaning(meaningStr);
                    break;
                case 5:
                    printf("Input frequency:\n");
                    cin>> frequency;
                    listWordsOutFrequency(frequency);
                    break;
                case 6:
                    printf("Thank your!\n");
                    return ;
                    break;
            default:
                printf("Wrong input!\nPlease input right operation number:\n");
                break;
            }
            printf("\n");
        }

    }
};


int main()
{
    ifstream ifs("word_utf8.txt");
    if(!ifs)
    {
        cout<<"Open file fail!";
        return 0;
    }
    DictClient client(ifs);
    client.run();
    return 0;
}
#ifndef WORD_ENTITY_H
#define WORD_ENTITY_H

#include<vector>
#include<string>
using namespace std;

enum WordProperty
{
    // 动词v（vi，vt)， 形容词adj，名词，介词
    verb, vi, vt, adjective, noun, prep
};

struct WordMeaningEntity
{
    WordProperty property;
    vector<string> meanings;
    WordMeaningEntity(string& wordMeaningStr, const int start, const int end) // [start, end)
    {
        switch (wordMeaningStr[start]+wordMeaningStr[start+1])
        {
            case 'p'+'r':
                property = WordProperty::prep;
            break;
            case 'a'+'d':
                property = WordProperty::adjective;
            break;
            case 'v'+'.':
                property = WordProperty::verb;
            case 'v'+'i':
                property = WordProperty::vi;
            break;
            case 'v'+'t':
                property = WordProperty::vt;
            break;
            default:
                property = WordProperty::noun;
            break;
        }
        int i, j;
        for (i =start; i < end&&wordMeaningStr[i]!='.'; i++) ;
        i++;
        for (j = i; j < end; j++)
            if(wordMeaningStr[j]==',')
            {
                meanings.push_back(wordMeaningStr.substr(i, j-i));
                i = j+1;
            }
        if(i>=end)
            i = start;
        meanings.push_back(wordMeaningStr.substr(i, j-i));
    }
};

struct wordEneity
{
    string wordSpell; // 单词的拼写
    string wordStr; // 单词的所有的含义的字符串形式（方便输出）
    vector<WordMeaningEntity > wordMeaningEntities; // 单词的意思（词性及含义）
    double frequency; // 单词出现的频率
    wordEneity(string& _wordSpell, string& wordMeaning, double _frequency)
    : wordSpell(_wordSpell), frequency(_frequency)
    {
        wordStr = _wordSpell+"\t"+wordMeaning+"\t"+to_string(_frequency);
        // adj.积极的,能起作用的,现行的,[语法]主动的,活动的,活跃的;n.[语法]主动语态,积极分子
        int start = 0;
        for (int i = 0; i < wordMeaning.size(); i++)
            if(wordMeaning[i]==';')
            {
                wordMeaningEntities.emplace_back(wordMeaning, start, i);
                start = i+1;
            }
        if(start<wordMeaning.size())
            wordMeaningEntities.emplace_back(wordMeaning, start, wordMeaning.size());
    }

    void printFormat()
    {
        printf("<spell>: %s\n", wordSpell.c_str());
        const vector<string> propertyStrs {"v", "vi", "vt", "adj", "n", "prep"};
        printf("<meaning>:\n");
        for (int i = 0; i < wordMeaningEntities.size(); i++)
        {
            auto& wordMeaningEntity = wordMeaningEntities[i];
            printf("\t%d. (%s): %s", i+1, propertyStrs[wordMeaningEntity.property].c_str(), wordMeaningEntity.meanings[0].c_str());
            for (int j = 1; j < wordMeaningEntity.meanings.size(); j++)
                printf(", %s", wordMeaningEntity.meanings[j].c_str());
            printf("\n");
        }
        printf("<frequency>: %.6lf\n", frequency);
    }

    string toString()
    {
        return wordStr;
    }
};


#endif
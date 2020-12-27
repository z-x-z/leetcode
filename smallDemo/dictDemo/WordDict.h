#ifndef WORD_DICT_H
#define WORD_DICT_H

#include "WordEneity.h"
#include <unordered_map>
#include <iostream>
#include <fstream>

class WordDict
{
    struct DictCountEntity
    {
        int toatalNums, verbNums, adjectiveNums, nounNums, prepNums;
        DictCountEntity(int toatalNums = 0, int verbNums = 0, int adjectiveNums = 0, int nounNums = 0, int prepNums = 0)
            : toatalNums(toatalNums), verbNums(verbNums), adjectiveNums(adjectiveNums), nounNums(nounNums), prepNums(prepNums)
        {
        }

        void print()
        {
            printf("词典中单词总数：%d, 形容词个数：%d，名词个数：%d，动词个数：%d，介词个数：%d\n",
                   toatalNums, verbNums, adjectiveNums, nounNums, prepNums);
        }
    };

private:
    vector<wordEneity> wordEneities;                  // 单词的集合
    unordered_map<string, int> spellSearchMap;        // 拼写搜索的映射
    unordered_multimap<string, int> meaningSearchMap; // 意义搜索的映射
    DictCountEntity *countEntity;

    void updateDictCount(int start = 0)
    {
        if (!countEntity)
            countEntity = new DictCountEntity();
        countEntity->toatalNums = wordEneities.size();
        for (int i = start; i < wordEneities.size(); i++)
        {
            auto &word = wordEneities[i];
            int isV = 0, isAdj = 0, isN = 0, isP = 0;
            for (auto &meaningEntity : word.wordMeaningEntities)
            {
                switch (meaningEntity.property)
                {
                case WordProperty::noun:
                    isN = 1;
                    break;
                case WordProperty::adjective:
                    isAdj = 1;
                    break;
                case WordProperty::prep:
                    isP = 1;
                    break;
                default:
                    isV = 1;
                    break;
                }
            }
            countEntity->verbNums += isV;
            countEntity->adjectiveNums += isAdj;
            countEntity->prepNums += isP;
            countEntity->nounNums += isN;
        }
    }

    void updateSpellSearchMap(int start = 0)
    {
        for (int i = start; i < wordEneities.size(); i++)
        {
            auto &word = wordEneities[i];
            spellSearchMap[word.wordSpell] = i;
        }
    }

    void updateMeaningSearchMap(int start = 0)
    {
        for (int i = start; i < wordEneities.size(); i++)
        {
            auto &word = wordEneities[i];
            for (auto &meaningEntity : word.wordMeaningEntities)
                for (auto &meaning : meaningEntity.meanings)
                    meaningSearchMap.insert(make_pair(meaning, i));
        }
    }

    void wordIdsOutFrequency(double frequency, vector<int> &ids)
    {
        for (int i = 0; i < wordEneities.size(); i++)
        {
            auto &word = wordEneities[i];
            if (word.frequency > frequency)
                ids.push_back(i);
        }
    }

public:
    WordDict(ifstream &ifs) : countEntity(nullptr)
    {
        string spell, stringMeaning;
        double frequency;
        int i = 0;
        while (ifs >> spell >> stringMeaning >> frequency)
        {
            // cout<<i++<<" ";
            wordEneities.emplace_back(spell, stringMeaning, frequency);
        }
    }
    int size()
    {
        return wordEneities.size();
    }

    void listDictWords()
    {
        for (auto &word : wordEneities)
            printf("%s\n", word.toString().c_str());
    }

    void printDictCount()
    {
        if (!countEntity)
            updateDictCount();
        countEntity->print();
    }

    void spellSearch(string wordSpell)
    {
        if (spellSearchMap.empty())
            updateSpellSearchMap();
        if (spellSearchMap.find(wordSpell) != spellSearchMap.end() && wordEneities[spellSearchMap[wordSpell]].wordMeaningEntities.size() > 0)
            wordEneities[spellSearchMap[wordSpell]].printFormat();
        else
            printf("Sorry, dict not contain the word which spell is \"%s\".", wordSpell.c_str());
    }

    void meaningSearch(string wordMeaning)
    {
        if (meaningSearchMap.empty())
            updateMeaningSearchMap();
        if (meaningSearchMap.find(wordMeaning) != meaningSearchMap.end())
        {
            printf("意思\"%s\"共查得%lu个单词:\n", wordMeaning.c_str(), meaningSearchMap.count(wordMeaning));
            auto range = meaningSearchMap.equal_range(wordMeaning);
            int i =1;
            for (auto it = range.first; it != range.second; it++)
            {
                printf("%d.\n", i++);
                wordEneities[it->second].printFormat();
            }
        }
        else
            printf("Sorry, dict not contain the word which meaning is \"%s\".", wordMeaning.c_str());
    }

    void listWordsOutFrequency(double frequency)
    {
        vector<int> wordIds;
        wordIdsOutFrequency(frequency, wordIds);
        for (auto id : wordIds)
            printf("%s\n", wordEneities[id].toString().c_str());
    }
};

#endif
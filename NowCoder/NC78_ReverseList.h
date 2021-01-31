#pragma once

#include "NowCoderDefines.h"
#include "INowCoderEntry.h"

class NC78_ReverseList : public INowCoderEntry
{
public:
    int MainEntry() override
    {
        std::cout << "NC78_ReverseList --> MainEntry" << std::endl;

        int tempValue = 0;
        ListNode *pInputList = new ListNode(0);
        ListNode *pTempNode = pInputList;

        while (std::cin >> tempValue)
        {
            pTempNode->next = new struct ListNode(tempValue);
            pTempNode = pTempNode->next;
        }

        NowCoderListNodePrint(pInputList->next);
        ListNode *pNewList = this->ReverseList(pInputList->next);
        NowCoderListNodePrint(pNewList);
        NowCoderListNodeRelease(&pInputList);

        return 0;
    }

public:
	ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL) return NULL;

        ListNode *pRetValue = pHead;
        ListNode *pRetValueCopy = pRetValue;
        ListNode *pTempNode = NULL;

        while (pRetValue->next)
        {
            pRetValue = pRetValue->next;
            pRetValueCopy->next = pTempNode;
            pTempNode = pRetValueCopy;
            pRetValueCopy = pRetValue;
        }
        pRetValue->next = pTempNode;

        return pRetValue;
	}
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "HeroGM.h"
#include "Hero.h"


FQuest AHeroGM::FindQuest_Implementation(FName QuestID, bool& Success)
{
	Success = false;

	FQuest Quest;
	if (QuestDatabase == nullptr) { return Quest; }

	for (int i = 0; i < QuestDatabase->QuestData.Num(); i++)
	{
		if (QuestDatabase->QuestData[i].QuestID == QuestID)
		{
			Success = true;
			return QuestDatabase->QuestData[i];

		}
	}

	return Quest;
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "TableSkil.h"

TableSkil::TableSkil()
{
	Cell.AddZeroed(10);
	Cell[0] = 0;//max firestacks
	Cell[1] = 10;//const damage
}

TableSkil::~TableSkil()
{
}

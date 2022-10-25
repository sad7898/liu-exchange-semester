package se.liu.ida.tdde45;

import se.liu.ida.tdde45.food.ingredients.cooked.CookedIngredient;
import se.liu.ida.tdde45.food.ingredients.cooked.CookedIngredientFactory.InvalidIngredientException;
import se.liu.ida.tdde45.food.ingredients.cooked.CookedIngredientFactory.UnknownIngredientException;
import se.liu.ida.tdde45.food.ingredients.raw.RawEgg;
import se.liu.ida.tdde45.food.ingredients.raw.RawPotato;
import se.liu.ida.tdde45.food.ingredients.raw.Yoghurt;
import se.liu.ida.tdde45.food.meals.Breakfast;
import se.liu.ida.tdde45.food.meals.Lunch;
import se.liu.ida.tdde45.house.Bed;
import se.liu.ida.tdde45.house.Bedroom;
import se.liu.ida.tdde45.house.Dresser;
import se.liu.ida.tdde45.house.Fridge.UnstockedException;
import se.liu.ida.tdde45.house.House;
import se.liu.ida.tdde45.house.Kitchen;
import se.liu.ida.tdde45.house.Stove.UnpoweredException;

public class Resident {
	public Resident(Kitchen kitchen) {
		this.kitchen = kitchen;
	}
	private final Kitchen kitchen;
	private boolean sick = false;
	
	protected Breakfast makeBreakfast() throws UnknownIngredientException, UnpoweredException, UnstockedException {
		final RawEgg rawEgg = kitchen.getFridge().getEgg();
		final Yoghurt yoghurt = kitchen.getFridge().getYoghurt();
		final Breakfast breakfast = new Breakfast(kitchen.getStove().boil(rawEgg), yoghurt);
		
		if(kitchen.getStove().isFilthy())
			sick = true;
		
		return breakfast;
	}

	protected Lunch makeLunch() throws InvalidIngredientException, UnknownIngredientException, UnpoweredException, UnstockedException {
		final RawEgg rawEgg = kitchen.getFridge().getEgg();
		final RawPotato rawPotato = kitchen.getFridge().getPotato();
		final CookedIngredient boiledPotato = kitchen.getStove().boil(rawPotato);
		final Lunch lunch = new Lunch(kitchen.getWorkbench().process(boiledPotato), kitchen.getStove().boil(rawEgg)); 
		
		if(kitchen.getStove().isFilthy())
			sick = true;
		
		return lunch;
	}
	
	public boolean isSick() {
		return sick;
	}
}

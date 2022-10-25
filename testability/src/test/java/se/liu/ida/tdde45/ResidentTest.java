package se.liu.ida.tdde45;

import org.testng.Assert;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.BeforeTest;
import org.testng.annotations.Test;

import se.liu.ida.tdde45.food.ingredients.cooked.CookedIngredientFactory.UnknownIngredientException;
import se.liu.ida.tdde45.house.Bed;
import se.liu.ida.tdde45.house.Bedroom;
import se.liu.ida.tdde45.house.Dresser;
import se.liu.ida.tdde45.house.Fridge;
import se.liu.ida.tdde45.house.House;
import se.liu.ida.tdde45.house.Kitchen;
import se.liu.ida.tdde45.house.Fridge.UnstockedException;
import se.liu.ida.tdde45.house.Stove.UnpoweredException;
import se.liu.ida.tdde45.mocks.MockBankConnector;
import se.liu.ida.tdde45.mocks.MockFridgeStocker;
import se.liu.ida.tdde45.singletons.BankConnector;
import se.liu.ida.tdde45.singletons.ChargingQueue;
import se.liu.ida.tdde45.singletons.CreditCardCharger;
import se.liu.ida.tdde45.singletons.FridgeStocker;
import se.liu.ida.tdde45.singletons.OrderDispatcher;
import se.liu.ida.tdde45.singletons.UninitializedSingletonException;

public class ResidentTest {

	Fridge f;
	Kitchen k;
	Resident r;
	MockFridgeStocker fs;

	@BeforeMethod
	public void setup() throws UninitializedSingletonException {
		fs = new MockFridgeStocker();
		f = new Fridge(fs);
		f.stock();
		k = new Kitchen(f);
		r = new Resident(k);
		
	}

	@Test
	public void testMakeBreakfast() 
			throws UnknownIngredientException, UnpoweredException, UnstockedException, UninitializedSingletonException {
		k.getStove().turnOn();
		r.makeBreakfast();
	}
	@Test
	public void testMakeBreakfastWithFilthyStoveShouldMakeResidentSick() throws UnknownIngredientException, UnpoweredException, UnstockedException {
		k.getStove().turnOn();
		k.getStove().setFilthy(true);
		r.makeBreakfast();
		Assert.assertTrue(r.isSick());
	}
	@Test
	public void testMakeBreakfastWithSwitchedOffFilthyStoveShouldNotMakeResidentSick() throws UnknownIngredientException, UnpoweredException, UnstockedException {
		k.getStove().setFilthy(true);
		try {
			r.makeBreakfast();
		}
		catch(UnpoweredException e) {
			Assert.assertFalse(r.isSick());
			return;
		}
		throw new AssertionError("Unknown Error");
	}

	// @Test(expectedExceptions = UninitializedSingletonException.class)
	// public void testMakeBreakfastFailsIfFridgeStockerIsNotInitialized()
	// 		throws UninitializedSingletonException, UnknownIngredientException, UnpoweredException, UnstockedException {

	// 	f.stock();
	// 	k.getStove().turnOn();
	// 	r.makeBreakfast();
	// }
}

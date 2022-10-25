package se.liu.ida.tdde45.house;

public class House {
	final private Kitchen kitchen;
	final private Bedroom bedroom ;
	
	public House(Bedroom bedroom, Kitchen kitchen) {
		this.bedroom = bedroom;
		this.kitchen = kitchen;
	}
	
	public Kitchen getKitchen() {
		return kitchen;
	}
	
	public Bedroom getBedroom() {
		return bedroom;
	}
}

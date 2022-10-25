package se.liu.ida.tdde45.singletons;

@SuppressWarnings("serial")
public class BankConnector {


	public BankConnector() {
		super();
	}
	

	
	public void withdraw() {
		throw new OopsError();
	}

	public static class OopsError extends Error {
		public OopsError() {
			super("Oops! You just withdrew cash from a real bank account!");
		}
	}
}

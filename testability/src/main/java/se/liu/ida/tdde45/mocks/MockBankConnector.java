package se.liu.ida.tdde45.mocks;

import se.liu.ida.tdde45.singletons.BankConnector;

public class MockBankConnector extends BankConnector {
    @Override
	public void withdraw() {
		return;
	}
}

package main;

import java.io.File;

import domain.BuildConfig;
import domain.FileFactory;
import domain.Project;
import xml.Build;
import xml.XMLBuildConfigurationReader;
import yaml.Compile;
import yaml.YamlBuildConfigurationReader;

public class Main {
	
	public static void main(String[] args) throws Exception {
		FileFactory factory = new FileFactory();
		factory.addBlueprint("xml", FileFactory.getXMLBlueprint());
		factory.addBlueprint("yaml", FileFactory.getYAMLBlueprint());
		final String target = "dist";
		factory.build("build.xml", target, 1);
		factory.build("build.yaml", target, 1);

	}
}

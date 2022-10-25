package domain;

import java.util.HashMap;
import java.util.function.Function;

import xml.Build;
import xml.XMLBuildConfigurationReader;
import yaml.Compile;
import yaml.YamlBuildConfigurationReader;

public class FileFactory {
	private HashMap<String,Function<String,XMLInterface>> blueprints;
	public FileFactory() {
		this.blueprints = new HashMap<String,Function<String,XMLInterface>>();
	}
	public void build(String fileName, String target,int debugLevel) throws Exception {
		Function<String,XMLInterface> method = this.blueprints.get(getFileFormat(fileName));
		if (method != null) {
			XMLInterface fileBuilder = method.apply(fileName);
			fileBuilder.build(debugLevel, target);
		}
		else {
			throw new Exception("Blueprint not found");
		}
	}
	public void addBlueprint(String name, Function<String,XMLInterface> method) {
		this.blueprints.put(name, method);
	}
	public static Function<String,XMLInterface> getXMLBlueprint() {
		return (String fileName) -> {
			XMLBuildConfigurationReader buildConfigurationReader = new XMLBuildConfigurationReader(fileName);
			final Project xmlProject = buildConfigurationReader.getProject();
			XMLInterface build = new XMLBuildWrapper(new Build(xmlProject));
			return build;
		};
	}
	public static Function<String,XMLInterface> getYAMLBlueprint() {
		return (String fileName) -> {
			YamlBuildConfigurationReader yamlConfigReader = new YamlBuildConfigurationReader(fileName);
			final BuildConfig yamlBuildConfig = yamlConfigReader.getBuildConfig();
			XMLAdapter adapter =  new XMLAdapter(yamlBuildConfig);
			return adapter;
		};
	}
	
	private static String getFileFormat(String file) {
		String[] f = file.split("\\.");
		String fileFormat = f[f.length-1];
		return fileFormat;
	}
}

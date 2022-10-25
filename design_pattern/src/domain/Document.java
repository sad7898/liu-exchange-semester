package domain;

import xml.Build;
import xml.XMLBuildConfigurationReader;
import yaml.Compile;
import yaml.YamlBuildConfigurationReader;

public class Document {
	public String fileName;
	public Document(String fileName) {
		this.fileName = fileName;
	}
	public String getFileFormat() {
		String[] f = this.fileName.split("\\.");
		String fileFormat = f[f.length-1];
		return fileFormat;
	}
	public BuildConfig getBuildConfig() throws Exception {
		if (this.getFileFormat().equals("xml")) {
			XMLBuildConfigurationReader buildConfigurationReader = new XMLBuildConfigurationReader(fileName);
			BuildConfig xmlBuildConfig = new BuildConfig();
			xmlBuildConfig.setProject(buildConfigurationReader.getProject());
			return xmlBuildConfig;
		}
		else if (this.getFileFormat().equals("yaml")) {
			YamlBuildConfigurationReader yamlConfigReader = new YamlBuildConfigurationReader(fileName);
			return yamlConfigReader.getBuildConfig();
		}
		else {
			throw new Exception();
		}
	}
}

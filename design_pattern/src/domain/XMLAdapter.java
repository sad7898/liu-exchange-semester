package domain;

import xml.Build;
import yaml.YamlBuildConfigurationReader;

public class XMLAdapter implements XMLInterface {
	private BuildConfig yamlBuildConfig;
	public XMLAdapter(BuildConfig yamlBuildConfig) {
		this.yamlBuildConfig = yamlBuildConfig;
	}
	public void build(int debuglevel, String targetName) {
		Project yamlProj = this.yamlBuildConfig.getProject();
		Build yamlbuild = new Build(yamlProj);
		yamlbuild.build(debuglevel, targetName);
	}
}

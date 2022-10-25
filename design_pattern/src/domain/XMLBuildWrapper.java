package domain;

import xml.Build;

public class XMLBuildWrapper implements XMLInterface {
    private Build build;
    public XMLBuildWrapper(Build build) {
        this.build = build;
    }
    public void build(int debuglevel, String targetName) {
        this.build.build(debuglevel, targetName);
    }
}

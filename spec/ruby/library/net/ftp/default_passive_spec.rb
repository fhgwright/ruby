require_relative '../../../spec_helper'

ruby_version_is ""..."3.1" do
  require_relative 'spec_helper'

  describe "Net::FTP#default_passive" do
    it "is true by default" do
      ruby_exe(fixture(__FILE__, "default_passive.rb")).should == "true\ntrue\n"
    end
  end
end

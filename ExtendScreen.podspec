#
# Be sure to run `pod lib lint MiniBrowser.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ExtendScreen'
  s.version          = '1.0.2'
  s.summary          = 'A short description of ExtendScreen.'

  s.description      = <<-DESC
  This is a remote control SDK
                       DESC

  s.homepage         = 'http://www.hiliad.com/'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'hiliad' => 'aili@hiliad.com' }
  s.source           = { :git => 'https://github.com/hanliang-tech/ExtendScreen.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '9.0'

  s.vendored_frameworks = 'ExtendScreen.xcframework'
  s.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 arm64' }
end

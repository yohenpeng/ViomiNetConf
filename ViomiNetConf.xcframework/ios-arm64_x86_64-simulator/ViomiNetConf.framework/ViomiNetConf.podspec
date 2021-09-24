Pod::Spec.new do |spec|
  spec.name         = "ViomiNetConf"
  spec.version      = "13"
  spec.summary      = "云米iOS ViomiNetConf SDK"
  spec.description  = <<-DESC
  云米iOS ViomiNetConf SDK
                   DESC
  spec.homepage     = "https://gitlab.viomi.com.cn/app/iOS/component/viomi_netconf_ios"
  spec.license      = { :type => "MIT", :file => "FILE_LICENSE" }
  spec.author             = { "彭依汉" => "pengyihan@viomi.com.cn" }
  spec.ios.deployment_target = "10.0"
  spec.source       = { :git => "https://gitlab.viomi.com.cn/app/iOS/component/viomi_netconf_ios.git", :tag => "#{spec.version}" }
  spec.vendored_framework  = "ViomiNetConf_Products/ViomiNetConf.xcframework"
  spec.user_target_xcconfig = { 'BUILD_LIBRARY_FOR_DISTRIBUTION' => 'YES' }
  spec.pod_target_xcconfig = {'DEFINES_MODULE' => 'YES'}
  spec.libraries = "iconv"
  spec.dependency "CocoaAsyncSocket"
  spec.dependency "BabyBluetooth"
  spec.dependency "YYModel"
  spec.dependency "YYCache"
  spec.dependency "AFNetworking"
  spec.dependency "libextobjc"
  spec.dependency "Logan"
  spec.dependency "fishhook"
  
end

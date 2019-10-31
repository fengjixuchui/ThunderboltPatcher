//
// Copyright © 2019 osy86. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>
#import "TPS6598XDevice.h"
#import "TBPPatchSet.h"

NS_ASSUME_NONNULL_BEGIN

@interface TBPManager : NSObject

@property (readonly) NSDictionary<NSString *, TPS6598XDevice *> *devices;

+ (TBPManager *)sharedInstance;
- (size_t)discoverDevices;
- (nullable TPS6598XDevice *)findDeviceWithPath:(nullable NSString *)path uuid:(nullable NSString *)uuid;
- (nullable NSData *)eepromDump:(TPS6598XDevice *)device at:(uint32_t)offset size:(uint32_t)size;
- (nullable NSArray<TBPPatchSet *> *)generatePatchSets:(NSArray *)rawPatches;
- (IOReturn)eepromPatch:(TPS6598XDevice *)device patches:(NSArray<TBPPatchSet *> *)patchSets reverse:(bool)reverse;

@end

NS_ASSUME_NONNULL_END

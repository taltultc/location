//
//  DGGeofencingHelper.h
//  Geofencing
//
//  Created by Dov Goldberg on 10/18/12.
//
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <Cordova/CDVJSON.h>
#import <Cordova/CDVPlugin.h>

enum DGLocationStatus {
    PERMISSIONDENIED = 1,
    POSITIONUNAVAILABLE,
    TIMEOUT,
    REGIONMONITORINGPERMISSIONDENIED,
    REGIONMONITORINGUNAVAILABLE,
    SIGNIFICANTLOCATIONMONITORINGUNAVAILABLE
};
typedef NSInteger DGLocationStatus;

enum DGLocationAccuracy {
    DGLocationAccuracyBestForNavigation,
    DGLocationAccuracyBest,
    DGLocationAccuracyNearestTenMeters,
    DGLocationAccuracyHundredMeters,
    DGLocationAccuracyThreeKilometers
};
typedef NSInteger DGLocationAccuracy;

// simple ojbect to keep track of location information
@interface DGLocationData : NSObject

@property (nonatomic) DGLocationStatus locationStatus;
@property (nonatomic) CLLocation* locationInfo;
@property (nonatomic) NSMutableArray* locationCallbacks;
@property (nonatomic) NSMutableArray* geofenceCallbacks;

@end

@class CDVCordovaView;
@interface DGGeofencingHelper : NSObject <CLLocationManagerDelegate>

@property (nonatomic) CLLocationManager *locationManager;
@property (nonatomic) CDVCordovaView *webView;
@property (nonatomic) BOOL didLaunchForRegionUpdate;
@property (nonatomic) DGLocationData* locationData;
@property (nonatomic) id <CDVCommandDelegate> commandDelegate;

+(DGGeofencingHelper*)sharedGeofencingHelper;

- (void) dispose;
+ (NSString*) applicationDocumentsDirectory;
- (void) returnLocationError: (NSUInteger) errorCode withMessage: (NSString*) message;
- (void) returnGeofenceError: (NSUInteger) errorCode withMessage: (NSString*) message;
- (void) returnRegionSuccess;
- (void) returnLocationSuccess;
- (void) saveGeofenceCallbackId:(NSString *) callbackId;
- (void) saveLocationCallbackId:(NSString *) callbackId;

@end

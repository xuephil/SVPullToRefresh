//
// UIScrollView+SVPullToRefresh.h
//
// Created by Sam Vermette on 23.04.12.
// Copyright (c) 2012 samvermette.com. All rights reserved.
//
// https://github.com/samvermette/SVPullToRefresh
//

#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>


@class SVPullToRefreshView;

@interface UIScrollView (SVPullToRefresh)

typedef NS_ENUM(NSUInteger, SVPullToRefreshPosition) {
    SVPullToRefreshPositionTop = 0,
    SVPullToRefreshPositionBottom,
};

- (void)addPullToRefreshWithActionHandler:(void (^)(void))actionHandler;
- (void)addPullToRefreshWithActionHandler:(void (^)(void))actionHandler position:(SVPullToRefreshPosition)position;
- (void)triggerPullToRefresh;

@property (nonatomic, strong, readonly) SVPullToRefreshView *pullToRefreshView;
@property (nonatomic, assign) BOOL showsPullToRefresh;

@end


typedef NS_ENUM(NSUInteger, SVPullToRefreshState) {
    SVPullToRefreshStateStopped = 0,
    SVPullToRefreshStateTriggered,
    SVPullToRefreshStateLoading,
    SVPullToRefreshStateAll = 10
};

@interface SVPullToRefreshView : UIView

+ (instancetype)appearance;

@property (nonatomic, strong) UIColor *arrowColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *textColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong, readonly) UILabel *titleLabel;
@property (nonatomic, strong, readonly) UILabel *subtitleLabel;
@property (nonatomic, strong, readwrite) UIColor *activityIndicatorViewColor NS_AVAILABLE_IOS(5_0) UI_APPEARANCE_SELECTOR;
@property (nonatomic, readwrite) UIActivityIndicatorViewStyle activityIndicatorViewStyle UI_APPEARANCE_SELECTOR;

@property (nonatomic, readonly) SVPullToRefreshState state;
@property (nonatomic, readonly) SVPullToRefreshPosition position;

- (void)setTitle:(NSString *)title forState:(SVPullToRefreshState)state;
- (void)setSubtitle:(NSString *)subtitle forState:(SVPullToRefreshState)state;
- (void)setCustomView:(UIView *)view forState:(SVPullToRefreshState)state;

- (void)startAnimating;
- (void)stopAnimating;

// deprecated; use setSubtitle:forState: instead
@property (nonatomic, strong, readonly) UILabel *dateLabel DEPRECATED_ATTRIBUTE;
@property (nonatomic, strong) NSDate *lastUpdatedDate DEPRECATED_ATTRIBUTE;
@property (nonatomic, strong) NSDateFormatter *dateFormatter DEPRECATED_ATTRIBUTE;

// deprecated; use [self.scrollView triggerPullToRefresh] instead
- (void)triggerRefresh DEPRECATED_ATTRIBUTE;

@end

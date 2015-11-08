#import "IOS_GLKViewOC.h"

@implementation IOS_GLKViewOC

- (void) drawRect:(CGRect)rect
{
    NSLog(@"IOS_GLKViewOC drawRect");
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

- (void) display
{
    NSLog(@"IOS_GLKViewOC drawRect");
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

@end
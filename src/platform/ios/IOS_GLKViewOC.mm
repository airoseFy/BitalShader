#import "IOS_GLKViewOC.h"

@implementation IOS_GLKViewOC

- (void) drawRect:(CGRect)rect
{
    NSLog(@"IOS_GLKViewOC drawRect");
//    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

- (id)initWithFrame:(CGRect)frame
{
    NSLog(@"IOS_GLKViewOC initWithFrame");
    self = [super initWithFrame:frame];
    
    if(self){
        GLKView *view = (GLKView *)self;
        view.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
        
        // Configure renderbuffers created by the view
        view.drawableColorFormat = GLKViewDrawableColorFormatRGBA8888;
        view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
        view.drawableStencilFormat = GLKViewDrawableStencilFormat8;
        
        // Enable multisampling
        view.drawableMultisample = GLKViewDrawableMultisample4X;
    }
    
    return self;
}

@end
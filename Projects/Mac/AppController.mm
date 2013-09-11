/**
 * Tooflya Inc. Development
 * @file AppController.mm
 * @category objective-c file
 *
 * @author Igor Mats from Tooflya Inc.
 * @copyright (c) 2013 by Igor Mats
 *
 * @license http://opensource.org/licenses/gpl-license.php GNU Public License v2
 * @all rights granted under this License are granted for the term of
 * copyright on the Program, and are irrevocable provided the stated
 * conditions are met. This License explicitly affirms your unlimited
 * permission to run the unmodified Program. The output from running a
 * covered work is covered by this License only if the output, given its
 * content, constitutes a covered work. This License acknowledges your
 * rights of fair use or other equivalent, as provided by copyright law.
 *
 * @version
 *
 */

#import "AppController.h"
#import "AppDelegate.h"

@implementation AppController

  static AppDelegate s_sharedApplication;

  @synthesize window, glView;

  -(void) applicationDidFinishLaunching:(NSNotification *)aNotification
  {
    NSRect rect = NSMakeRect(200, 200, 1136, 640);
    window = [[NSWindow alloc] initWithContentRect:rect
      styleMask:( NSClosableWindowMask | NSTitledWindowMask )
      backing:NSBackingStoreBuffered
      defer:YES];

    NSOpenGLPixelFormatAttribute attributes[] = {
      NSOpenGLPFADoubleBuffer,
      NSOpenGLPFADepthSize, 32,
      NSOpenGLPFAStencilSize, 8,
      0
    };

    NSOpenGLPixelFormat *pixelFormat = [[[NSOpenGLPixelFormat alloc] initWithAttributes:attributes] autorelease];

    glView = [[EAGLView alloc] initWithFrame:rect pixelFormat:pixelFormat];

    [window becomeFirstResponder];
    [window setContentView:glView];
    [window setTitle:@"Real Steel by Tooflya Inc. 2013"];
    [window makeKeyAndOrderFront:self];
    [window setAcceptsMouseMovedEvents:YES];

    cocos2d::CCApplication::sharedApplication()->run();
  }

  -(BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication
  {
    return YES;
  }

  -(void) dealloc
  {
    cocos2d::CCDirector::sharedDirector()->end();
    [super dealloc];
  }

#pragma mark -
#pragma mark IB Actions

  -(IBAction) toggleFullScreen:(id)sender
  {
    EAGLView* pView = [EAGLView sharedEGLView];
    [pView setFullScreen:!pView.isFullScreen];
  }

  -(IBAction) exitFullScreen:(id)sender
  {
    [[EAGLView sharedEGLView] setFullScreen:NO];
  }

@end
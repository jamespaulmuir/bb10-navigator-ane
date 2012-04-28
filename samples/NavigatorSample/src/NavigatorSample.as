/*
 * Copyright (c) 2012 James Paul Muir
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package
{

	import com.jamespaulmuir.bb10.Navigator;
	import com.jamespaulmuir.bb10.NavigatorBadge;
	
	import flash.display.Sprite;
	import flash.display.StageAlign;
	import flash.display.StageScaleMode;
	import flash.events.AccelerometerEvent;
	import flash.events.MouseEvent;
	import flash.sensors.Accelerometer;
	import flash.text.TextFormat;
	import flash.text.TextFormatAlign;
	
	import qnx.fuse.ui.buttons.LabelButton;
	import qnx.fuse.ui.text.Label;
	import qnx.system.AudioManager;
	
	[SWF(height="600", width="1024", frameRate="30", backgroundColor="#BABABA")]
	public class NavigatorSample extends Sprite
	{
		
		private var setBadgeButton:LabelButton;
		private var clearBadgeButton:LabelButton;
		
		public function NavigatorSample()
		{
			
			setBadgeButton = new LabelButton();
			setBadgeButton.label = "Set Badge";
			setBadgeButton.width = 150;
			setBadgeButton.x = stage.stageWidth / 2 - setBadgeButton.width / 2;
			setBadgeButton.y = stage.stageHeight / 2 - 50;
			
			clearBadgeButton = new LabelButton();
			clearBadgeButton.label = "Clear Badge";
			clearBadgeButton.width = 150;
			clearBadgeButton.x = stage.stageWidth / 2 - setBadgeButton.width / 2; 
			clearBadgeButton.y = stage.stageHeight / 2 + 50;

			setBadgeButton.addEventListener(MouseEvent.CLICK, onSetBadgeButtonClick);
			clearBadgeButton.addEventListener(MouseEvent.CLICK, onClearBadgeButtonClick);
			
			addChild(setBadgeButton);
			addChild(clearBadgeButton);
			
			
			stage.nativeWindow.visible = true;
		}
		
	
		
		private function onSetBadgeButtonClick(event:MouseEvent):void
		{
			var success:Boolean = Navigator.setBadge(NavigatorBadge.NAVIGATOR_BADGE_SPLAT);
		}
		
		private function onClearBadgeButtonClick(event:MouseEvent):void
		{
			var success:Boolean = Navigator.clearBadge();
		}
	}
}
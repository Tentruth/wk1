<GameFile>
  <PropertyGroup Name="EnemyNode" Type="Node" ID="507bf541-f15d-4099-b8ce-f6d502cbf9b1" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="40" Speed="1.0000">
        <Timeline ActionTag="1729716933" Property="Position">
          <PointFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="-1">
              <Points>
                <PointF />
                <PointF />
                <PointF X="1.0000" Y="1.0000" />
                <PointF X="1.0000" Y="1.0000" />
              </Points>
            </EasingData>
          </PointFrame>
          <PointFrame FrameIndex="40" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="1729716933" Property="Scale">
          <ScaleFrame FrameIndex="0" X="1.0000" Y="1.0000">
            <EasingData Type="-1">
              <Points>
                <PointF />
                <PointF />
                <PointF X="1.0000" Y="1.0000" />
                <PointF X="1.0000" Y="1.0000" />
              </Points>
            </EasingData>
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1729716933" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="-1">
              <Points>
                <PointF />
                <PointF />
                <PointF X="1.0000" Y="1.0000" />
                <PointF X="1.0000" Y="1.0000" />
              </Points>
            </EasingData>
          </ScaleFrame>
          <ScaleFrame FrameIndex="40" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="1729716933" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="40" Value="255">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-51836152" Property="FileData">
          <TextureFrame FrameIndex="0" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_00.png" Plist="Resouce/scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="5" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_01.png" Plist="Resouce/scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="10" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_02.png" Plist="Resouce/scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="15" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_03.png" Plist="Resouce/scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="20" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_04.png" Plist="Resouce/scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="25" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_05.png" Plist="Resouce/scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="30" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_06.png" Plist="Resouce/scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="35" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_07.png" Plist="Resouce/scene101.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="40" Tween="False">
            <TextureFile Type="PlistSubImage" Path="flame1_00.png" Plist="Resouce/scene101.plist" />
          </TextureFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="EnemyNode" Tag="14" ctype="GameNodeObjectData">
        <Size X="0.0000" Y="0.0000" />
        <Children>
          <AbstractNodeData Name="body" ActionTag="1729716933" Tag="17" IconVisible="True" ctype="SingleNodeObjectData">
            <Size X="0.0000" Y="0.0000" />
            <Children>
              <AbstractNodeData Name="triouter_4" ActionTag="-1603923921" Tag="19" IconVisible="False" LeftMargin="-88.8918" RightMargin="-82.1082" TopMargin="-97.5647" BottomMargin="-70.4353" ctype="SpriteObjectData">
                <Size X="171.0000" Y="168.0000" />
                <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
                <Position X="-3.3918" Y="13.5647" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="triouter.png" Plist="Resouce/scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
              <AbstractNodeData Name="triblock_3" ActionTag="1284973030" Tag="18" IconVisible="False" LeftMargin="-84.0000" RightMargin="-84.0000" TopMargin="-77.0868" BottomMargin="-66.9132" ctype="SpriteObjectData">
                <Size X="168.0000" Y="144.0000" />
                <AnchorPoint />
                <Position X="-84.0000" Y="-66.9132" />
                <Scale ScaleX="1.0000" ScaleY="1.0000" />
                <CColor A="255" R="255" G="255" B="255" />
                <PrePosition />
                <PreSize X="0.0000" Y="0.0000" />
                <FileData Type="PlistSubImage" Path="triblock.png" Plist="Resouce/scene101.plist" />
                <BlendFunc Src="1" Dst="771" />
              </AbstractNodeData>
            </Children>
            <AnchorPoint />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
          </AbstractNodeData>
          <AbstractNodeData Name="flame" ActionTag="-51836152" Tag="15" IconVisible="False" LeftMargin="-120.0000" RightMargin="-120.0000" TopMargin="-110.0000" BottomMargin="-110.0000" ctype="SpriteObjectData">
            <Size X="240.0000" Y="220.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="flame1_00.png" Plist="Resouce/scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="shadow" ActionTag="-396247026" Tag="20" IconVisible="False" LeftMargin="-63.0607" RightMargin="-73.9393" TopMargin="128.1872" BottomMargin="-151.1872" ctype="SpriteObjectData">
            <Size X="137.0000" Y="23.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="5.4393" Y="-139.6872" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="PlistSubImage" Path="trishadow.png" Plist="Resouce/scene101.plist" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>
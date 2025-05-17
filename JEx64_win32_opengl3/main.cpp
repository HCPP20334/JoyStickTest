#include "JoyStickTest_module.h"
#pragma comment (lib , "Urlmon.lib")
namespace ImGui {
    void TextToBool(const char* label, bool v) {
        ImVec4 col = v? ImVec4(1.0f, 1.0f, 1.0f, 1.0f) : ImVec4(0.50f, 0.50f, 0.50f, 1.0f);
        ImGui::TextColored(col, label);
    }
    void TextRGBABool(const char* label,ImVec4 colRGBA_in,ImVec4 colRGBA_out ,bool v) {
        ImVec4 col = v ? GUI->RGBA2IV4(colRGBA_in.x, colRGBA_in.y, colRGBA_in.z, colRGBA_in.w) : GUI->RGBA2IV4(colRGBA_out.x, colRGBA_out.y, colRGBA_out.z, colRGBA_out.w);
        ImGui::TextColored(col, label);
    }
    float CircleAxis(const char* label, float v) {
        ImGui::BeginGroup(); // Группируем элементы
        ImVec2 canvasSize = ImVec2(128, 128);

        // Добавляем текст и получаем позицию canvas
        ImGui::Text("%s : %.1f", label,v);
        ImVec2 canvasPos = ImGui::GetCursorScreenPos();

        ImDrawList* drawList = ImGui::GetWindowDrawList();
        ImU32 border_color = ImGui::GetColorU32(ImGuiCol_Border);
        ImGuiStyle& style = ImGui::GetStyle();

        // Отрисовка фона и границы
        float radius = canvasSize.x * 0.5f;
        ImVec2 center = ImVec2(canvasPos.x + radius, canvasPos.y + radius);

        // Фоновый круг
        drawList->AddCircleFilled(
            center,
            radius - style.FrameBorderSize,
            IM_COL32(0, 0, 0, 0)
        );

        // Граница (рисуем круг вместо прямоугольника)
        if (style.FrameBorderSize > 0.0f) {
            drawList->AddCircle(
                center,
                radius - style.FrameBorderSize * 0.5f,
                border_color,
                0, // Автоматическое количество сегментов
                style.FrameBorderSize
            );
        }

        // Положение стика (предполагаем, что v - нормализованное значение [-1, 1])
        ImVec2 stickPos = ImVec2(
            center.x + v * (radius - 10.0f), // Учитываем размер маркера
            center.y + v * (radius - 10.0f)
        );

        // Маркер стика
        drawList->AddCircleFilled(
            stickPos,
            10.0f,
            ImGui::GetColorU32(ImVec4(0.34f, 0.06f, 0.98f, 1.00f))
        );

        // Перемещаем курсор для следующих элементов ImGui
        ImGui::Dummy(canvasSize);
        ImGui::EndGroup();

        return 0;
    }
    float CircleAxisXY(const char* label, float v, float v1) {
        ImGui::BeginGroup(); // Группируем элементы
        ImVec2 canvasSize = ImVec2(128, 128);

        // Добавляем текст и получаем позицию canvas
        ImGui::Text("%s : %.1f : %.1f", label, v,v1);
        ImVec2 canvasPos = ImGui::GetCursorScreenPos();

        ImDrawList* drawList = ImGui::GetWindowDrawList();
        ImU32 border_color = ImGui::GetColorU32(ImGuiCol_Border);
        ImGuiStyle& style = ImGui::GetStyle();

        // Отрисовка фона и границы
        float radius = canvasSize.x * 0.5f;
        ImVec2 center = ImVec2(canvasPos.x + radius, canvasPos.y + radius);

        // Фоновый круг
        drawList->AddCircleFilled(
            center,
            radius - style.FrameBorderSize,
            IM_COL32(0, 0, 0, 0)
        );

        // Граница (рисуем круг вместо прямоугольника)
        if (style.FrameBorderSize > 0.0f) {
            drawList->AddCircle(
                center,
                radius - style.FrameBorderSize * 0.5f,
                border_color,
                0, // Автоматическое количество сегментов
                style.FrameBorderSize
            );
        }

        // Положение стика (предполагаем, что v - нормализованное значение [-1, 1])
        ImVec2 stickPos = ImVec2(
            center.x + v * (radius - 10.0f), // Учитываем размер маркера
            center.y + v1 * (radius - 10.0f)
        );

        // Маркер стика
        drawList->AddCircleFilled(
            stickPos,
            10.0f,
            ImGui::GetColorU32(ImVec4(0.34f, 0.06f, 0.98f, 1.00f))
        );

        // Перемещаем курсор для следующих элементов ImGui
        ImGui::Dummy(canvasSize);
        ImGui::EndGroup();

        return 0;
    }
    float ButtonGamepad(const char* label, bool v) {
        ImGui::BeginGroup();
        ImVec2 canvasSize = ImVec2(32, 32);

        ImVec2 canvasPos = ImGui::GetCursorScreenPos();
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        ImDrawList* drawList = ImGui::GetWindowDrawList();
        ImU32 border_color = ImGui::GetColorU32(ImGuiCol_Border);
        ImGuiStyle& style = ImGui::GetStyle();
        float radius = canvasSize.x * 0.5f;

        // Рассчитываем размер текста
        ImVec2 text_size = ImGui::CalcTextSize(label);

        // Вычисляем центр кнопки
        ImVec2 center = ImVec2(canvasPos.x + radius, canvasPos.y + radius);

        // Позиция текста (центрированная)
        ImVec2 text_pos = ImVec2(
            center.x - text_size.x * 0.5f,
            center.y - text_size.y * 0.5f
        );

        // Отрисовка текста через drawList
        if (style.FrameBorderSize > 0.0f) {
            drawList->AddCircle(
                center,
                radius - style.FrameBorderSize * 0.5f,
                border_color,
                0, // Автоматическое количество сегментов
                style.FrameBorderSize
            );
        }

        // Фоновый круг
        drawList->AddCircleFilled(
            center,
            radius - style.FrameBorderSize,
            v ? ImGui::GetColorU32(ImVec4(0.34f, 0.06f, 0.98f, 1.00f)) :
            ImGui::GetColorU32(ImVec4(0.36f, 0.36f, 0.36f, 1.0f))
        );
        drawList->AddText(text_pos, ImGui::GetColorU32(ImGuiCol_Text), label);

        // Положение стика (предполагаем, что v - нормализованное значение [-1, 1])
      
        // Перемещаем курсор для следующих элементов ImGui
        ImGui::Dummy(canvasSize);
        ImGui::EndGroup();

        return 0;
    }
    bool CustomToggle(const char* label, bool* v) {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        ImGui::PushID(label);
        ImGui::TextColored((*v ? ImVec4(1.0f, 1.0f, 1.0f, 1.00f): ImVec4(0.65f, 0.65f, 0.65f, 1.00f)), label);
        ImGui::SameLine();
        float height = ImGui::GetFrameHeight();
        float width = height * 1.55f;
        ImGuiStyle& style = ImGui::GetStyle();

        ImVec2 p = ImGui::GetCursorScreenPos();

        // Colors
        ImU32 color_bg_on = ImGui::GetColorU32(ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
        ImU32 color_bg_off = ImGui::GetColorU32(ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
        ImU32 color_knob = *v ? ImGui::GetColorU32(ImVec4(0.34f, 0.06f, 0.98f, 1.00f)) :
            ImGui::GetColorU32(ImVec4(0.36f, 0.36f, 0.36f, 1.0f));
        ImU32 glow_color = ImGui::GetColorU32(ImVec4(0.34f, 0.06f, 0.98f, 0.3f)); // Цвет свечения
        ImU32 border_color = ImGui::GetColorU32(ImGuiCol_Border);

        ImGui::InvisibleButton(label, ImVec2(width, height));
        bool clicked = ImGui::IsItemClicked();
        if (clicked) *v = !(*v);

        // Background + Border
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), *v ? color_bg_on : color_bg_off, height);

        if (style.FrameBorderSize > 0.0f) {
            draw_list->AddRect(
                p,
                ImVec2(p.x + width, p.y + height),
                border_color,
                height * 0.5f,
                0,
                style.FrameBorderSize
            );
        }

        // Knob parameters
        float base_radius = *v ? 10 : 8;
        ImVec2 knob_pos = *v ?
            ImVec2(p.x + width - height * 0.5f, p.y + height * 0.5f) :
            ImVec2(p.x + height * 0.5f, p.y + height * 0.5f);

        // Glow effect (only when active)
        if (*v) {
            // Рисуем несколько слоев для эффекта свечения
            const int glow_layers = 3;
            for (int i = 0; i < glow_layers; i++) {
                float alpha = 0.3f * (1.0f - (float)i / glow_layers);
                float radius = base_radius + 2.0f * (i + 1);
                draw_list->AddCircle(
                    knob_pos,
                    radius,
                    ImGui::GetColorU32(ImVec4(0.34f, 0.06f, 0.98f, alpha)),
                    0, // сегменты (0 = автоматически)
                    2.0f // толщина линии
                );
            }
        }

        // Main knob
        draw_list->AddCircleFilled(knob_pos, base_radius, color_knob);

        ImGui::PopID();
        return clicked;
    }
    
    bool Spinner(const char* label, float radius, int thickness, const ImU32& color) {
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);

        ImVec2 pos = window->DC.CursorPos;
        ImVec2 size((radius) * 2, (radius + style.FramePadding.y) * 2);

        const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));
        ItemSize(bb, style.FramePadding.y);
        if (!ItemAdd(bb, id))
            return false;

        // Render
        window->DrawList->PathClear();

        int num_segments = 30;
        int start = abs(ImSin(g.Time * 1.8f) * (num_segments - 5));

        const float a_min = IM_PI * 2.0f * ((float)start) / (float)num_segments;
        const float a_max = IM_PI * 2.0f * ((float)num_segments - 3) / (float)num_segments;

        const ImVec2 centre = ImVec2(pos.x + radius, pos.y + radius + style.FramePadding.y);

        for (int i = 0; i < num_segments; i++) {
            const float a = a_min + ((float)i / (float)num_segments) * (a_max - a_min);
            window->DrawList->PathLineTo(ImVec2(centre.x + ImCos(a + g.Time * 8) * radius,
                centre.y + ImSin(a + g.Time * 8) * radius));
        }

        window->DrawList->PathStroke(color, false, thickness);
    }
    bool CustomSliderFloat(const char* label, float* value, float min, float max, ImVec2 size = ImVec2(100, 16)) {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);

        const ImVec2 text_size = ImGui::CalcTextSize(label);
        const float text_offset_x = (text_size.x > 0.0f)
            ? style.ItemInnerSpacing.x + text_size.x
            : 0.0f;

        // Правильное создание векторов
        const ImRect frame_bb(
            window->DC.CursorPos,
            ImVec2(
                window->DC.CursorPos.x + size.x,
                window->DC.CursorPos.y + size.y
            )
        );

        const ImRect total_bb(
            frame_bb.Min,
            ImVec2(
                frame_bb.Max.x + text_offset_x,
                frame_bb.Max.y + ImMax(0.0f, text_size.y - size.y)
            )
        );
        ImGui::ItemSize(total_bb, style.FramePadding.y);
        if (!ImGui::ItemAdd(total_bb, id, &frame_bb))
            return false;

        // Обработка ввода
        bool hovered, held;
        bool clicked = ImGui::ButtonBehavior(frame_bb, id, &hovered, &held);
        if (clicked || held) {
            const float mouse_pos = (g.IO.MousePos.x - frame_bb.Min.x) / size.x;
            *value = ImClamp(mouse_pos * (max - min) + min, min, max);
        }

        // Цвета
        const ImU32 bg_color = ImGui::GetColorU32(ImGuiCol_FrameBg);
        const ImU32 fill_color = ImGui::GetColorU32(ImGuiCol_SliderGrabActive);
        const ImU32 knob_color = ImGui::GetColorU32((held && hovered) ? ImGuiCol_SliderGrabActive :
            hovered ? ImGuiCol_SliderGrab :
            ImGuiCol_SliderGrab);

        // Отрисовка
        ImDrawList* draw_list = ImGui::GetWindowDrawList();

        // Фон
        draw_list->AddRectFilled(frame_bb.Min, frame_bb.Max, bg_color, style.FrameRounding);

        // Заполненная область
        const float t = (*value - min) / (max - min);
        const ImRect fill_bb(frame_bb.Min, ImVec2(frame_bb.Min.x + size.x * t, frame_bb.Max.y));
        draw_list->AddRectFilled(fill_bb.Min, fill_bb.Max, fill_color, style.FrameRounding);

        // Бегунок
        const float knob_radius = size.y * 0.8f;
        const ImVec2 knob_center = ImVec2(
            frame_bb.Min.x + size.x * t,
            frame_bb.Min.y + size.y * 0.5f
        );
        draw_list->AddCircleFilled(knob_center, knob_radius, knob_color, 16);

        // Текст
        ImGui::RenderText(ImVec2(frame_bb.Max.x + style.ItemInnerSpacing.x, frame_bb.Min.y), label);

        return clicked || held;
    }
}
uint64_t fDataMemUsage() // Work Function !!! Check Sym RAM to Current Program //
{
    PROCESS_MEMORY_COUNTERS pmc;
    pmc.cb = sizeof(pmc);
    GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
    return pmc.WorkingSetSize;
}

#pragma once


// Simple helper function to load an image into a OpenGL texture with common settings
bool LoadTextureFromFile(const char* filename, GLuint* out_texture, int* out_width, int* out_height,unsigned char *imgBuffer) {
    int image_width = 0;
    int image_height = 0;
    unsigned char* image_data = stbi_load(filename, &image_width, &image_height, NULL, 4);
    *imgBuffer = *image_data;
    if (image_data == NULL)
        return false;

    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);

    // Setup filtering parameters for display
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);

    *out_texture = image_texture;
    *out_width = image_width;
    *out_height = image_height;

    glBindTexture(GL_TEXTURE_2D, 0);

    return true;
}
int64_t fSndMsg(int64_t fJEid_snd)
{
    int64_t fSnd00 = 0xFFFFFFF;
    int64_t fSnd01 = 0x00000010L;
    int64_t fSnd02 = 0x00000040L;
    int64_t fSnd03 = 0x00000030L;
    //
    int64_t fSoundThread = 0;
    switch (fJEid_snd)
    {
    case 1:
        fSoundThread = fSnd00;
    case 2:
        fSoundThread = fSnd01;//Critical Error 
    case 3:
        fSoundThread = fSnd02;
    case 4:
        fSoundThread = fSnd03;
        break;
    }
    MessageBeep((UINT)(fSoundThread));
    return fSoundThread;
}
bool LoadTextOnFile(char* File, uint64_t fStrLineMax,std::string* f_buffer,std::string* getfile,bool *Tb_state)
{
   std::string fLoadbuffer;
    int64_t fBuf_lineCounts = 0;
    std::ifstream FileRes(File);
    int64_t  fCbuf = 0;
    fStrLineMax = 5;
    bool EndReadFile;
    *getfile = File;
    if (!FileRes.is_open())
    {
        *f_buffer = "Error: resource falled!";
    }
    while(1)
    {
       std::getline(FileRes, fLoadbuffer);
        fCbuf++;
        if (fCbuf <= 30)
        {
            fCbuf = 0;
            fLoadbuffer = fLoadbuffer + "\n";
            return -1;
        }
        if (fBuf_lineCounts >= fStrLineMax)
        {
            EndReadFile = true;
            return Tb_state;
            free(f_buffer);
        }
         *f_buffer = *f_buffer + fLoadbuffer;
    }
}
int64_t ResetBool(bool *State)
{
    *State = false;
    return 0;
    fSndMsg(1);
    
}
typedef double  long float64_t;
// Data stored per platform window
struct WGL_WindowData { HDC hDC; };

// Data
static HGLRC            g_hRC;
static WGL_WindowData   g_MainWindow;
static int              g_Width;
static int              g_Height;

// Forward declarations of helper functions
bool CreateDeviceWGL(HWND hWnd, WGL_WindowData* data);
void CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data);

//
uint64_t id = 0;
int64_t  idx = 0;



const GLubyte* fJ_vendor = glGetString(GL_VENDOR);// Returns the vendor
const GLubyte* fJ_rendered = glGetString(GL_RENDERER);
//
void ResetDeviceWGL();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

static int64_t ld_V(std::string *buff,std::string* debug_str)
{
    std::string fBuffer_fIn = "01234567890/,./<>[{||*&^%$#@@}]";
    int64_t fBufferSizeOffset = fBuffer_fIn.size();
    uint64_t InTimeData = GetTickCount64();
    uint64_t OutTimeData = 0;
    uint64_t stackPointOut = 0;
    uint64_t randPointOffset = 0;
    for (int64_t stackPoint = 0; stackPoint < 1000000; stackPoint++)
    {
        srand(time(0));
        stackPointOut = stackPoint;
        randPointOffset = rand() % fBufferSizeOffset;
        fBuffer_fIn = fBuffer_fIn + fBuffer_fIn[randPointOffset];
        fBufferSizeOffset = fBuffer_fIn.size();
    }
    OutTimeData = GetTickCount64();
    *buff = std::to_string((float)(OutTimeData - InTimeData) / 3.14f);
    *debug_str = std::to_string(stackPointOut) + " count\nbufferSizeOffset:" + std::to_string((fBufferSizeOffset / 1024)) + " :KiB Loaded";
}
bool b_Msg = false;
uint64_t ImMessage(const char* str_text, const char* title_text)
{
   
    if (b_Msg)
    {
        ImGui::Begin(str_text, &b_Msg);
        ImGui::Text(title_text);
        if (ImGui::SmallButton("OK")) { b_Msg = false; }

        // *b_event = b_Msg;
        ImGui::End();
        return strlen(str_text);
    }
}
static bool kButton(bool state, bool bSameLine,std::string value) {
    if (state) {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.34f, 0.06f, 0.98f, 1.00f));
    }
    if (!state) {
        ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.30f, 0.30f, 0.30f, 0.80f));
    }
    ImGui::Button((value).c_str(),ImVec2(50,50));
    ImGui::PopStyleColor();
    if (bSameLine) {
        ImGui::SameLine();
    }
    return state;
}
class ClockSystem {
public:
        uint64_t fC_second = fLTime(2);
        
};
static std::string SwapTextStr(int64_t code) {
    return std::to_string((char)code);
}
void StyleColorsDracula(ImGuiStyle* dst) {
    ImGuiStyle* style = dst ? dst : &ImGui::GetStyle();
    ImVec4* colors = style->Colors;

    colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.1f, 0.13f, 1.0f };
    colors[ImGuiCol_MenuBarBg] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_Border] = ImVec4{ 0.44f, 0.37f, 0.61f, 0.29f };
    colors[ImGuiCol_BorderShadow] = ImVec4{ 0.0f, 0.0f, 0.0f, 0.24f };
    colors[ImGuiCol_Text] = ImVec4{ 1.0f, 1.0f, 1.0f, 1.0f };
    colors[ImGuiCol_TextDisabled] = ImVec4{ 0.5f, 0.5f, 0.5f, 1.0f };
    colors[ImGuiCol_Header] = ImVec4{ 0.13f, 0.13f, 0.17, 1.0f };
    colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
    colors[ImGuiCol_HeaderActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_Button] = ImVec4{ 0.13f, 0.13f, 0.17, 1.0f };
    colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
    colors[ImGuiCol_ButtonActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_CheckMark] = ImVec4{ 0.74f, 0.58f, 0.98f, 1.0f };
    colors[ImGuiCol_PopupBg] = ImVec4{ 0.1f, 0.1f, 0.13f, 0.92f };
    colors[ImGuiCol_SliderGrab] = ImVec4{ 0.44f, 0.37f, 0.61f, 0.54f };
    colors[ImGuiCol_SliderGrabActive] = ImVec4{ 0.74f, 0.58f, 0.98f, 0.54f };
    colors[ImGuiCol_FrameBg] = ImVec4{ 0.13f, 0.13, 0.17, 1.0f };
    colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
    colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_Tab] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TabHovered] = ImVec4{ 0.24, 0.24f, 0.32f, 1.0f };
    colors[ImGuiCol_TabActive] = ImVec4{ 0.2f, 0.22f, 0.27f, 1.0f };
    colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TitleBg] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_ScrollbarBg] = ImVec4{ 0.1f, 0.1f, 0.13f, 1.0f };
    colors[ImGuiCol_ScrollbarGrab] = ImVec4{ 0.16f, 0.16f, 0.21f, 1.0f };
    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4{ 0.19f, 0.2f, 0.25f, 1.0f };
    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4{ 0.24f, 0.24f, 0.32f, 1.0f };
    colors[ImGuiCol_Separator] = ImVec4{ 0.44f, 0.37f, 0.61f, 1.0f };
    colors[ImGuiCol_SeparatorHovered] = ImVec4{ 0.74f, 0.58f, 0.98f, 1.0f };
    colors[ImGuiCol_SeparatorActive] = ImVec4{ 0.84f, 0.58f, 1.0f, 1.0f };
    colors[ImGuiCol_ResizeGrip] = ImVec4{ 0.44f, 0.37f, 0.61f, 0.29f };
    colors[ImGuiCol_ResizeGripHovered] = ImVec4{ 0.74f, 0.58f, 0.98f, 0.29f };
    colors[ImGuiCol_ResizeGripActive] = ImVec4{ 0.84f, 0.58f, 1.0f, 0.29f };
#ifdef IMGUI_HAS_DOCK
    colors[ImGuiCol_DockingPreview] = ImVec4{ 0.44f, 0.37f, 0.61f, 1.0f };
#endif
}
static bool bTh_Classic = true;
static bool bTh_Dark = false;
static bool bTh_Light = false;
int main(int, char**)
{

    static std::string fBuffer0 = 

        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄⠄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠄⠄⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠄⠄⠄⠄⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
        "⣿⠟⠛⠛⠋⠉⠉⠉⠄⠄⠄⠄⠐⠒⠒⠶⣶⣤⡀⠄⠄⠄⠉⠉⠉⠙⠛⠛⠻⣿"
        "⣿⣦⡀⠄⠄⠄⠄⠄⠄⠄⠄⠄⣠⣶⣶⣶⠈⠻⣿⣆⠄⠄⠄⠄⠄⠄⠄⣠⣾⣿"
        "⣿⣿⣿⣦⡀⠄⠄⠄⠄⠄⢀⣼⣿⣿⣿⠁⠄⠄⢹⣿⡇⠄⠄⠄⠄⣠⣾⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣶⣄⠄⠄⠄⠙⢿⡿⠋⠻⣿⣦⣀⣸⣿⡿⠄⠄⣠⣾⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⡗⠄⠄⢀⣤⡀⠄⠄⠈⢿⣿⣿⣿⠃⠄⢾⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⡇⢀⣴⣿⣿⣿⣷⣶⣶⣿⣿⣿⣿⣷⣄⢸⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣿⠄⠺⣿⡿⠁⠄⠉⠉⠉⠉⠄⠄⠙⢿⠏⠈⣿⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⡏⠄⠄⠈⠄⠄⣀⣤⣾⣶⣤⡀⠄⠄⠄⠄⠄⢻⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⠃⠄⢀⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡀⠄⠸⣿⣿⣿⣿⣿⣿"
        "⣿⣿⣿⣿⣿⣿⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣿⣿⣿⣿⣿⣿";
  
  
    // Create application window
    ImGui_ImplWin32_EnableDpiAwareness();
    WNDCLASSEXW wc = { sizeof(wc), CS_OWNDC, WndProc, 0L, 0L, GetModuleHandle(nullptr), nullptr, nullptr, nullptr, nullptr, L"JE x64", nullptr };
    wc.hIcon = LoadIcon(wc.hInstance, MAKEINTRESOURCE(103));
    ::RegisterClassExW(&wc);
    HWND hwnd = ::CreateWindowW(wc.lpszClassName, L"JoyStickTest 1.2.2 OpenGL3_SSE4.2 (C++20)", WS_OVERLAPPEDWINDOW | WS_EX_TOOLWINDOW |  WS_EX_NOPARENTNOTIFY, 100, 80, 800, 540, nullptr, nullptr, wc.hInstance, nullptr);

    // Initialize OpenGL
    if (!CreateDeviceWGL(hwnd, &g_MainWindow))
    {
        CleanupDeviceWGL(hwnd, &g_MainWindow);
        ::DestroyWindow(hwnd);
        ::UnregisterClassW(wc.lpszClassName, wc.hInstance);
        return 1;
    }
    wglMakeCurrent(g_MainWindow.hDC, g_hRC);

    // Show the window
   // ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::AnimateWindow(hwnd, 100, AW_BLEND);
    ::ShowWindow(GetConsoleWindow(), 2);
    ::UpdateWindow(hwnd);
    std::string fStrParam;
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;   // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;    // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    ImGui_ImplWin32_InitForOpenGL(hwnd);
    ImGui_ImplOpenGL3_Init();
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF(".\\WhiteRabbit.ttf", 13.0f);
    std::ifstream Set_prm("JE_CONFIG.TXT");
    Set_prm.is_open();
    while (std::getline(Set_prm, fStrParam))
    {
        if (fStrParam == "fJE_Font=false;") { JTModule->fFontsState = false; }if (fStrParam == "fJE_Font=true;") { JTModule->fFontsState = true; }
        if (fStrParam == "fJETheme=0;") { bTh_Dark = true; bTh_Light = false; bTh_Classic = false; }
        if (fStrParam == "fJETheme=1;") { bTh_Dark = false; bTh_Light = false; bTh_Classic = true; }
        if (fStrParam == "fJETheme=2;") { bTh_Dark = false; bTh_Light = false; bTh_Classic = false; }
        if (fStrParam == "fJEVsync=true;") { JTModule->b_vsync = true; }if (fStrParam == "fJEVsync=false;") { JTModule->b_vsync = false; }
        if (fStrParam == "fJEInvertVibrationValue=true;") { JTModule->v_bInvertVibValue = true; }if (fStrParam == "fJEInvertVibrationValue=false;") { JTModule->v_bInvertVibValue = false; }
    }

    ImFont* font1 = 0;
    ImFont* font2 = 0;
    ImFont* font3 = 0;
    if (JTModule->fFontsState)
    {
        io.Fonts->AddFontFromFileTTF(".\\PixelizerBold.ttf", 20.0f);
        font1 = io.Fonts->AddFontFromFileTTF("PixelizerBold.ttf", 20.0f);
        font2 = io.Fonts->AddFontFromFileTTF("PixelizerBold.ttf", 40.0f);
        font3 = io.Fonts->AddFontFromFileTTF("PixelizerBold.ttf", 15.0f);
    }
    else
    {
        io.Fonts->AddFontFromFileTTF(".\\roboto.ttf", 20.0f);//
        font1 = io.Fonts->AddFontFromFileTTF("roboto.ttf", 20.0f);
        font2 = io.Fonts->AddFontFromFileTTF("roboto.ttf", 40.0f);
        font3 = io.Fonts->AddFontFromFileTTF("roboto.ttf", 15.0f);

    }
    struct GPU_DATA {
        std::string E_Brand = (const char*)glGetString(GL_VENDOR);
        std::string E_Model = (const char*)glGetString(GL_RENDERER);
        std::string E_GLVer = (const char*)glGetString(GL_VERSION);
    };
    GPU_DATA GPU;
    std::string fD_gpuBrand = GPU.E_Brand;
    std::string fD_gpuModel = GPU.E_Model;
    std::string fD_gpuGLVer = GPU.E_GLVer;
    SetColorAMD64(240);
   // std::cout << "" << "OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "" << std::endl;
    int CPUInfo[4] = { -1 };
    unsigned   nExIds, i = 0;
    char CPUBrandString[0x40];
    // Get the information associated with each extended ID.
    __cpuid(CPUInfo, 0x80000000);
    nExIds = CPUInfo[0];
    for (i = 0x80000000; i <= nExIds; ++i)
    {
        __cpuid(CPUInfo, i);
        // Interpret CPU brand string
        if (i == 0x80000002)
            memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000003)
            memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
        else if (i == 0x80000004)
            memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
    }
    // Main loop
    bool done = false;
    ShowWindow(GetConsoleWindow(),0);
    const char* strFiles[] = { "test.png", "icon_amd_radeon.png" };
    GLuint GLArrayBuffer;
    GLuint GLArrayBuffer_1;
    int64_t a, b;
    int Ix = 128; int Iy = 128;
    int Ix1 = 128; int Iy1 = 128;
    unsigned char imgBuffer;
    unsigned char imgBufferAMD;
    bool load = LoadTextureFromFile(strFiles[0], &GLArrayBuffer, &Ix, &Iy, &imgBuffer);
    bool amdLogo = LoadTextureFromFile(strFiles[1], &GLArrayBuffer_1, &Ix1, &Iy1, &imgBufferAMD);
    IM_ASSERT(load);
    IM_ASSERT(amdLogo);
    static bool dgwnd = false;
    static std::string dCPUBrandString = CPUBrandString;
    while (!done)
    {

        // Poll and handle messages (inputs, window resize, etc.)
        // See the WndProc() function below for our to dispatch events to the Win32 backend.
        MSG msg;
        JTModule->fWFrame = true;
        bool fB_loadFrame = false;
        while (::PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
        {
            std::exception d;
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            if (msg.message == WM_QUIT)
                exit(0);
              //  done = true;
            if (msg.message == WM_DESTROY)
                exit(0);
        }
        
        if (done)
            break;
        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
           
           // fJEFrame = false;
           // std::cout << "[JE_ENGINE] Frame Cra" << std::endl;
          //  std::cout << "ADDR:" << &d << "->" << d << std::endl;
            ImGui::Begin("\tJE x64_OpenGL3_SSE4.2 C++20",&JTModule->fJEFrame, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove );
                // Create a window called "Hello, world!" and append into it.

                ImGui::SetWindowPos(ImVec2(-1.0f, 25.0f));
                ImGui::SetWindowSize(ImVec2(800.0f, 480.0f));
                JTModule->JEApp.ClearFreeMemory();
                std::ofstream WriteConfigJE("JE_CONFIG.TXT");
                // ImGui::Begin("THEME EDITOR", &v_bThemeJE);
                ImGuiStyle& style = ImGui::GetStyle();
                if (bTh_Classic) {
                    bTh_Dark = false;
                    bTh_Light = false;
                    bTh_Classic = true;
                    // ImGui::StyleColorsClassic(); fStrMsgBuf = "Theme 1 Apply!!";  WriteConfigJE.is_open();
                    StyleColorsDracula(&style);
                    WriteConfigJE << "fJETheme=1;" << std::endl;
                    //WriteConfigJE.close();
                }
                if (bTh_Light) {
                    bTh_Dark = false;
                    bTh_Classic = false;
                    bTh_Light = true;
                    ImGui::StyleColorsLight();
                    WriteConfigJE.is_open();
                    WriteConfigJE << "fJETheme=2;" << std::endl;
                    //WriteConfigJE.close();
                }
                if (bTh_Dark)
                {
                    bTh_Light = false;
                    bTh_Classic = false;
                    bTh_Dark = true;
                    JTModule->fStrMsgBuf = "Theme 0";
                    WriteConfigJE.is_open();
                    WriteConfigJE << "fJETheme=0;" << std::endl;
                    //WriteConfigJE.close();
                    
                    ImGuiStyle& style = ImGui::GetStyle();
                    ImVec4* colors = ImGui::GetStyle().Colors;
                    colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
                    colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
                    colors[ImGuiCol_WindowBg] = ImVec4(0.04f, 0.04f, 0.04f, 0.94f);
                    colors[ImGuiCol_ChildBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.0f);
                    colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);
                    colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
                    colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
                    colors[ImGuiCol_FrameBg] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
                    colors[ImGuiCol_FrameBgHovered] = ImVec4(0.48f, 0.26f, 0.98f, 0.40f);
                    colors[ImGuiCol_FrameBgActive] = ImVec4(0.37f, 0.00f, 1.00f, 1.00f);
                    colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
                    colors[ImGuiCol_TitleBgActive] = ImVec4(0.21f, 0.16f, 0.48f, 1.00f);
                    colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
                    colors[ImGuiCol_MenuBarBg] = ImVec4(0.11f, 0.11f, 0.11f, 1.00f);
                    colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
                    colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
                    colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
                    colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
                    colors[ImGuiCol_CheckMark] = ImVec4(0.45f, 0.26f, 0.98f, 1.00f);
                    colors[ImGuiCol_SliderGrab] = ImVec4(0.48f, 0.26f, 0.98f, 1.0f);
                    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.48f, 0.26f, 0.98f, 0.52f);
                    colors[ImGuiCol_Button] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
                    colors[ImGuiCol_ButtonHovered] = ImVec4(0.34f, 0.06f, 0.98f, 1.00f);
                    colors[ImGuiCol_ButtonActive] = ImVec4(0.34f, 0.06f, 0.98f, 1.00f);
                    colors[ImGuiCol_Header] = ImVec4(0.0f, 0.0f, 0.0f, 0.0f);
                    colors[ImGuiCol_HeaderHovered] = ImVec4(0.15f, 0.15f, 0.15f, 0.80f);
                    colors[ImGuiCol_HeaderActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.04f);
                    colors[ImGuiCol_Separator] = ImVec4(0.34f, 0.06f, 0.98f, 1.00f);
                    colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
                    colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
                    colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.04f);
                    colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.13f);
                    colors[ImGuiCol_ResizeGripActive] = ImVec4(0.38f, 0.38f, 0.38f, 1.00f);
                    colors[ImGuiCol_TabHovered] = ImVec4(0.40f, 0.26f, 0.98f, 0.50f);
                    colors[ImGuiCol_Tab] = ImVec4(0.18f, 0.20f, 0.58f, 0.73f);
                    //colors[ImGuiCol_TabSelected] = ImVec4(0.29f, 0.20f, 0.68f, 1.00f);
                  ///  colors[ImGuiCol_TabSelectedOverline] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
                    //colors[ImGuiCol_TabDimmed] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
                  //  colors[ImGuiCol_TabDimmedSelected] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
                    //colors[ImGuiCol_TabDimmedSelectedOverline] = ImVec4(0.50f, 0.50f, 0.50f, 0.00f);
                    colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
                    colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
                    colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
                    colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
                    colors[ImGuiCol_TableHeaderBg] = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
                    colors[ImGuiCol_TableBorderStrong] = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
                    colors[ImGuiCol_TableBorderLight] = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
                    colors[ImGuiCol_TableRowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
                    colors[ImGuiCol_TableRowBgAlt] = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
                    //colors[ImGuiCol_TextLink] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
                    colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.04f);
                    colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
                    // colors[ImGuiCol_NavCursor] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
                    colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
                    colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
                    colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
                    style.WindowRounding = 10;
                    style.FrameRounding = 10;
                    style.FrameBorderSize = 1;
                    style.GrabRounding = 10;
                    style.GrabMinSize = 20;
                   
                }
                //ImGui::Text(("b0:" + std::to_string(bTh_Classic) + "b1:" + std::to_string(bTh_Dark) + "b1:" + std::to_string(bTh_Light)).c_str());
                JTModule->JEApp.ClearFreeMemory();
                if (JTModule->b_vsync) {
                    Sleep(13);
                    WriteConfigJE << "fJEVsync=true;" << std::endl;
                }
                else {
                    Sleep(0);
                    WriteConfigJE << "fJEVsync=false;" << std::endl;
                }
                if (GetAsyncKeyState(VK_ESCAPE)) {
                    JTModule->v_bExit = true;
                }
                if (dgwnd) {
                    std::exception mainStack;
                    ImGui::Text("f=%p", &JTModule->v_bExit);
                    std::cout << "f=" << &JTModule->v_bExit << std::endl;
                    ImGui::Begin("1d", &dgwnd, ImGuiWindowFlags_NoCollapse + ImGuiWindowFlags_NoTitleBar);
                    ImGui::SetWindowSize(ImVec2(600.0f, 600.0f));
                    ImGui::Text(("b_vsync:" + std::to_string(JTModule->b_vsync)+"\tstack:=%p").c_str(), &JTModule->b_vsync);
                    ImGui::Text(("fL_motor:"+std::to_string(JTModule->fL_motor)+"\tstack:=%p").c_str(), &JTModule->fL_motor);
                    ImGui::Text(("fL_motor:"+std::to_string(JTModule->fL_motor)+"\tstack:=%p").c_str(), &JTModule->fR_motor);
                    ImGui::Text(("v_flagClMemory:" + std::to_string(JTModule->v_flagClMemory)+"\tstack:=%p").c_str(), &JTModule->v_flagClMemory);
                    ImGui::Text(("imgBufferAMD:" + std::to_string(imgBufferAMD)+"\tstack:=%p").c_str(), &imgBufferAMD);
                    ImGui::Text(("v_bExit:" + std::to_string(JTModule->v_bExit)+"\tstack:=%p").c_str(), &JTModule->v_bExit);
                    ImGui::Text(("v_Rmotor:"+std::to_string(JTModule->v_Rmotor)+"\tstack:=%p").c_str(), &JTModule->v_Rmotor);
                    ImGui::Text(("v_Lmotor:" + std::to_string(JTModule->v_Lmotor)+"\tstack:=%p").c_str(), &JTModule->v_Lmotor);
                    ImGui::Text(("v_bSettings:" + std::to_string(JTModule->v_bSettings) + "\tstack:=%p").c_str(), &JTModule->v_bSettings);
                    ImGui::Text(("v_bSettingsCh_b:"+std::to_string(JTModule->v_bSettingsCh_b)+"\tstack:=%p").c_str(), &JTModule->v_bSettingsCh_b);
                    ImGui::Text(("v_bInvertVibValue:" + std::to_string(JTModule->v_bInvertVibValue)+"\tstack:=%p").c_str(), &JTModule->v_bInvertVibValue);
                    ImGui::Text(("rd_text:"+std::to_string(JTModule->rd_text)+"\tstack:=%p").c_str(), &JTModule->rd_text);
                    ImGui::Text(("v_Penis:"+std::to_string(JTModule->v_Penis)+"\tstack:=%p").c_str(), &JTModule->v_Penis);
                    ImGui::Text(("fFontsState:"+std::to_string(JTModule->fFontsState)+"\tstack:=%p").c_str(), &JTModule->fFontsState);
                    ImGui::Text(("imgBufferAMD:"+std::to_string(imgBufferAMD)+"\tstack:=%p").c_str(), &imgBufferAMD);
                    ImGui::Text(("v_bThemeJE:"+std::to_string(JTModule->v_bThemeJE)+"\tstack:=%p").c_str(), &JTModule->v_bThemeJE);
                    ImGui::Text(("bTh_Classic:"+std::to_string(bTh_Classic)+"\tstack:=%p").c_str(), &bTh_Classic);
                    ImGui::Text(("bTh_Dark:"+std::to_string(bTh_Dark)+"\tstack:=%p").c_str(), &bTh_Dark);
                    ImGui::Text(("bTh_Light:"+std::to_string(bTh_Light)+"\tstack:=%p").c_str(), &bTh_Light);
                    ImGui::Text(("Gamepad_enable:"+std::to_string(JTModule->Gamepad_enable)+"\tstack:=%p").c_str(), &JTModule->Gamepad_enable);
                    ImGui::Text(("C_XinputControllerState=" + std::to_string(JTModule->C_XinputControllerState) + "\tstack=%p").c_str(), &JTModule->C_XinputControllerState);
                    ImGui::End();
                }
                if (JTModule->v_bSettings)
                {
                    ImGui::Begin("SETTINGS", &JTModule->v_bSettings, ImGuiWindowFlags_NoCollapse);
                    JTModule->JEApp.ClearFreeMemory();
                    // ImGui::Image((void*)(intptr_t)out_texture, ImVec2(Ix, Ix));
                    if (JTModule->v_bSettings) { JTModule->v_bSettingsCh_b = true; }
                    //ImGui::Checkbox("AUTO CLEARNING MEMORY(DEBUG)", &v_flagClMemory);fInvertYBool
                    ImGui::SeparatorText("MAIN SETTINGS");
                    ImGui::CustomToggle("VSYNC", &JTModule->b_vsync); ImGui::SameLine(); ImGui::TextColored((JTModule->b_vsync ? ImVec4(0.65f, 0, 1.0f, 1.0f) : ImVec4(1, 0, 0.33f, 1.0f)), (JTModule->b_vsync ? "Enabled" : "Disabled"));
                    ImGui::CustomToggle("INVERT VIBRATION VALUE FOR EMU XINPUT", &JTModule->v_bInvertVibValue); ImGui::SameLine(); ImGui::TextColored((JTModule->v_bInvertVibValue ? ImVec4(0.65f, 0, 1.0f, 1.0f) : ImVec4(1, 0, 0.33f, 1.0f)), (JTModule->v_bInvertVibValue ? "Enabled" : "Disabled"));
                    ImGui::CustomToggle("Gamepad API:", &JTModule->Gamepad_enable); ImGui::SameLine(); ImGui::Text((!JTModule->Gamepad_enable ? "JoyStickAPI(Xinput)" : "ImGui Gamepad API"));
                    ImGui::CustomToggle("Invert Y Axis:", &JTModule->fInvertYBool); ImGui::SameLine(); ImGui::Text((JTModule->fInvertYBool ? "Enable" : "Disable"));
                    ImGui::TextColored((JTModule->fFontsState ? ImVec4(0.65f, 0, 1.0f, 1.0f) : ImVec4(1, 0, 0.33f, 1.0f)), "Need Restart App");
                    ImGui::CustomToggle("SELECT FONTS", &JTModule->fFontsState); ImGui::SameLine(); ImGui::TextColored((JTModule->fFontsState ? ImVec4(0.65f, 0, 1.0f, 1.0f) : ImVec4(1, 0, 0.33f, 1.0f)), (JTModule->fFontsState ? "PixelizerBold" : "roboto"));
                    ImGui::CustomToggle("Debug Info",&dgwnd);
                    ImGui::SeparatorText("THEME EDITOR");
                    ImGui::CustomToggle("DARK", &bTh_Dark);
                    ImGui::SameLine();
                    ImGui::CustomToggle("LIGHT", &bTh_Light);
                    ImGui::SameLine();
                    ImGui::CustomToggle("CLASSIC", &bTh_Classic);
                    ImGui::BeginChild("f", ImVec2(0, 100), ImGuiChildFlags_Border | ImGuiChildFlags_FrameStyle);
                    ImGui::PushFont(font3);
                    ImGui::Text(("CPU:" + dCPUBrandString).c_str());//
                    ImGui::Text(("GPU:" + (fD_gpuModel)).c_str());
                    ImGui::Text(("GPU GL:" + (fD_gpuGLVer)).c_str());
                    ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f, 1.0f), ("[--RAM Memory--]\nMemory Load:" + std::to_string(fMemStatus(1))+":Procents | "+(std::to_string(fMemStatus(7) - fMemStatus(4))) + ":GB\nFree Memory:" + std::to_string(fMemStatus(4)) + " :GB\nTotal Memory" + std::to_string(fMemStatus(7)) + " :GB").c_str());
                    ImGui::PopFont();
                    ImGui::EndChild();
                    //ImMessage("Test_00", "Test Window");
                    //  ImGui::SliderInt("Win Volume", &fC_vol, 0, 100, "", 0);
                    if (GetAsyncKeyState((char)'W') && GetAsyncKeyState((char)VK_LCONTROL))
                    {
                        keybd_event(VK_VOLUME_UP, 0x45, KEYEVENTF_EXTENDEDKEY | 0, NULL);
                    }
                    if (GetAsyncKeyState((char)'S') && GetAsyncKeyState((char)VK_LCONTROL))
                    {
                        keybd_event(VK_VOLUME_DOWN, 0x45, KEYEVENTF_EXTENDEDKEY | 0, NULL);
                    }
                    //ImGuiKey_GamepadBack
                    if (ImGui::Button("SAVE"))
                    {
                        std::ofstream buf("restart.bat");
                        buf.is_open();
                        buf << "taskkill /im JEx64OpenGL.exe>nul\n";
                        buf << "start ./JEx64OpenGL.exe>nul\n";
                        buf << " del restart.bat>nul" << std::endl;
                        buf << "exit" << std::endl;
                        buf.close();
                        WinExec("restart.bat", 1);
                    }
                    if (JTModule->v_bInvertVibValue)
                    {
                        WriteConfigJE << "fJEInvertVibrationValue=true;" << std::endl;
                    }
                    else
                    {
                        WriteConfigJE << "fJEInvertVibrationValue=false;" << std::endl;
                    }
                    if (JTModule->fFontsState)
                    {
                        //ImGui::Text("Selected WhiteRabbit!!");
                        JTModule->fStrMsgBuf = "FONT WHITERABBIT!!";
                        WriteConfigJE << "fJE_Font=true;" << std::endl;
                        // WriteConfigJE.close();
                    }
                    else
                    {
                        //WriteConfigJE.is_open();
                        WriteConfigJE << "fJE_Font=false;" << std::endl;
                        // WriteConfigJE.close();
                         //UpdateWindow(hwnd);
                         //ImGui::Text("Selected unispace bd!!");
                        JTModule->fStrMsgBuf = "FONT UNISPACE BD!!";
                    }

                    ImGui::End();
                }
                JTModule->JEApp.ClearFreeMemory();
                if (GetAsyncKeyState('C')) {
                    MessageBoxA(hwnd, ("CPU:" + dCPUBrandString + "\ngpu_model: " + fD_gpuModel + "\ngpu_brand: " + fD_gpuBrand + "\ngpu_OpenGL_version: " + fD_gpuGLVer[0]+ fD_gpuGLVer[1]+ fD_gpuGLVer[2]+"\n[--Memory--]-RAM\nMemory Load:"+std::to_string(fMemStatus(1))+"%\nFree Memory:"+std::to_string(fMemStatus(4))+" :GB\nTotal Memory"+std::to_string(fMemStatus(7))+" :GB").c_str(), "JoyStickTest PC Hardware", 1);
                }
                static bool fJEUpdate = false;
                //XINPUT_STATE fDJUP;
                ImGui::BeginMainMenuBar();
                ImGui::PushFont(font1);
                ImGui::MenuItem("SETTINGS", "", &JTModule->v_bSettings, true);
                ImGui::MenuItem("ABOUT", "", &JTModule->fCAboutW, true);
                ImGui::MenuItem("CPUTEST", "", &JTModule->bCPUTest, true);
                ImGui::MenuItem("GPUTEST", "", &JTModule->bGPUTest, true);
                ImGui::MenuItem("KeyBoard Test", "", &JTModule->bKbTest, true);
                ImGui::MenuItem("UPDATE", "", &fJEUpdate, true);
                ImGui::MenuItem("EXIT", "", &JTModule->v_bExit, true);
                ImGui::PopFont();
                if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B && JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A && JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y)
                {
                    JTModule->v_Penis = true;
                }
                //  static bool v_bExMsg = true;
                if (GetAsyncKeyState('G')) {
                    a++;
                    if (a > 20) {
                        a = 0;
                    }
                    if (((a == 20) ? true : false)) {
                        ImGui::Text("OK");
                        JTModule->v_Penis = true;
                   }
                }
                
                if (JTModule->v_bExit)
                {
                    // exit:
                    JTModule->JEApp.ClearFreeMemory();
                    ImGui::Begin("EXIT");
                    ImGui::PushFont(font2);
                    ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), ":: WARNING!!! ::");
                    ImGui::PopFont();
                    ImGui::PushFont(font1);
                    ImGui::Text("\n:: SETTINGS NOT SAVED!! ::\n:: USER DATA WILL BE  LOST!! ::");
                    ImGui::PopFont();
                    if (ImGui::Button("SAVE AND EXIT",ImVec2(150.0f, 40.0f))) { ImGui::Text("Thanks!!why used my app!!"); WriteConfigJE.close(); Sleep(1000); exit(0); }
                    ImGui::SameLine();
                    if (ImGui::Button("BACK",ImVec2(150.0f,40.0f))) { JTModule->v_bExit = false; }
                    ImGui::End();
                }
                ImGui::EndMainMenuBar();
                JTModule->JEApp.ClearFreeMemory();
                static std::string key_pull;
               // JTModule->xController1->GetBatteryState(&b_data, &b_type, &bStrStatus);
                if (JTModule->bKbTest) {
                    ImGui::Begin("kb_test", &JTModule->bKbTest);
                    ImGui::Text(("key_pullup: " + key_pull).c_str());
                    // Ассоциативный массив: ключ — код клавиши, значение — строковое представление
                    static const std::unordered_map<int, std::string> keyMap = {
                        {'1', "k1"}, {'Q', "kQ"},
                        {'2', "k2"}, {'W', "kW"},
                        {'3', "k3"}, {'E', "kE"},
                        {'4', "k4"}, {'R', "kR"},
                        {'5', "k5"}, {'T', "kT"},
                        {'6', "k6"}, {'Y', "kY"},
                        {'7', "k7"}, {'U', "kU"},
                        {'8', "k8"}, {'I', "kI"},
                        {'9', "k9"}, {'O', "kO"},
                        {'0', "k0"}, {'P', "kP"},
                        {'A', "kA"}, {'V', "kV"},
                        {'S', "kS"}, {'B', "kB"},
                        {'D', "kD"}, {'N', "kN"},
                        {'F', "kF"}, {'M', "kM"},
                        {'G', "kG"}, {VK_DIVIDE, "k/"},
                        {'H', "kH"}, {'.', "k."},
                        {'J', "kJ"}, {VK_ESCAPE, "kESC"},
                        {'K', "kK"}, {VK_F1, "kf1"},
                        {'L', "kL"}, {VK_F2, "kf2"},
                        {';', "k;"}, {VK_F3, "kf3"},
                        {'"', "k'"}, {VK_F4, "kf4"},
                        {'Z', "kZ"}, {VK_F5, "kf5"},
                        {'X', "kX"}, {VK_F6, "kf6"},
                        {'C', "kC"}, {VK_F7, "kf7"},
                        {VK_F8, "kf8"}, {VK_F9, "kf9"},
                        {VK_F10, "kf10"}, {VK_F11, "kf11"},
                        {VK_F12, "kf12"}
                    };
                    static bool bp0 = false; static bool bp12 = false; static bool bp24 = false;
                    static bool bp1 = false; static bool bp13 = false; static bool bp25 = false;
                    static bool bp2 = false; static bool bp14 = false; static bool bp26 = false;
                    static bool bp3 = false; static bool bp15 = false; static bool bp27 = false;
                    static bool bp4 = false; static bool bp16 = false; static bool bp28 = false;
                    static bool bp5 = false; static bool bp17 = false; static bool bp29 = false;
                    static bool bp6 = false; static bool bp18 = false; static bool bp30 = false;
                    static bool bp7 = false; static bool bp19 = false; static bool bp31 = false;
                    static bool bp8 = false; static bool bp20 = false; static bool bp32 = false;
                    static bool bp9 = false; static bool bp21 = false; static bool bp33 = false;
                    static bool bp10 = false; static bool bp22 = false; static bool bp34 = false;
                    static bool bp11 = false; static bool bp23 = false; static bool bp35 = false;
                    std::string key2;
                    kButton(bp0, true, "1");
                    kButton(bp1, true, "2");
                    kButton(bp2, true, "3");
                    kButton(bp3, true, "4");
                    kButton(bp4, true, "5");
                    kButton(bp5, true, "6");
                    kButton(bp6, true, "7");
                    kButton(bp7, true, "8");
                    kButton(bp8, true, "9");
                    kButton(bp9, false, "0");
                    kButton(bp10, true, "q");
                    kButton(bp11, true, "w");
                    kButton(bp12, true, "e");
                    kButton(bp13, true, "r");
                    kButton(bp14, true, "t");
                    kButton(bp15, true, "y");
                    kButton(bp16, true, "u");
                    kButton(bp17, true, "i");
                    kButton(bp18, true, "o");
                    kButton(bp19, false, "p");
                    kButton(bp20, true, "a");
                    kButton(bp21, true, "s");
                    kButton(bp22, true, "d");
                    kButton(bp23, true, "f");
                    kButton(bp24, true, "g");
                    kButton(bp25, true, "h");
                    kButton(bp26, true, "j");
                    kButton(bp27, true, "k");
                    kButton(bp28, false, "l");
                    kButton(bp29, true, "z");
                    kButton(bp30, true, "x");
                    kButton(bp31, true, "c");
                    kButton(bp32, true, "v");
                    kButton(bp33, true, "b");
                    kButton(bp34, true, "n");
                    kButton(bp35, true, "m");
                    static int64_t key_id = 0;
                    
                    
                    // Проверяем каждую клавишу в ассоциативном массиве
                    for (const auto& [key, keyName] : keyMap) {
                        if (GetAsyncKeyState(key)) {
                            
                            key_id++;
                            key_pull = "\n" + std::to_string(key_id) + "->kid->" + keyName;
                            key2 = keyName;
                            if (keyName == "k1") { bp0 = true; }if (keyName == "k4") { bp3 = true; }if (keyName == "k7") { bp6 = true; }
                            if (keyName == "k2") { bp1 = true; }if (keyName == "k5") { bp4 = true; }if (keyName == "k8") { bp7 = true; }
                            if (keyName == "k3") { bp2 = true; }if (keyName == "k6") { bp5 = true; }if (keyName == "k9") { bp8 = true; }
                            if (keyName == "k0") { bp9 = true; }if (keyName == "kQ") { bp10 = true; }if (keyName == "kW") { bp11 = true; }
                            if (keyName == "kE") { bp12 = true; }if (keyName == "kR") { bp13 = true; }if (keyName == "kT") { bp14 = true; }
                            if (keyName == "kY") { bp15 = true; }if (keyName == "kU") { bp16 = true; }if (keyName == "kI") { bp17 = true; }
                            if (keyName == "kO") { bp18 = true; }if (keyName == "kP") { bp19 = true; }if (keyName == "kA") { bp20 = true; }
                            if (keyName == "kS") { bp21 = true; }if (keyName == "kD") { bp22 = true; }if (keyName == "kF") { bp23 = true; }
                            if (keyName == "kG") { bp24 = true; }if (keyName == "kH") { bp25 = true; }if (keyName == "kJ") { bp26 = true; }
                            if (keyName == "kK") { bp27 = true; }if (keyName == "kL") { bp28 = true; }if (keyName == "kZ") { bp29 = true; }
                            if (keyName == "kX") { bp30 = true; }if (keyName == "kC") { bp31 = true; }if (keyName == "kV") { bp32 = true; }
                            if (keyName == "kB") { bp33 = true; }if (keyName == "kN") { bp34 = true; }if (keyName == "kM") { bp35 = true; }
                            //
                            if (keyName != "k1") { bp0 = false; }if (keyName != "k4") { bp3 = false; }if (keyName != "k7") { bp6 = false; }
                            if (keyName != "k2") { bp1 = false; }if (keyName != "k5") { bp4 = false; }if (keyName != "k8") { bp7 = false; }
                            if (keyName != "k3") { bp2 = false; }if (keyName != "k6") { bp5 = false; }if (keyName != "k9") { bp8 = false; }
                            if (keyName != "k0") { bp9 = false; }if (keyName != "kQ") { bp10 = false; }if (keyName != "kW") { bp11 = false; }
                            if (keyName != "kE") { bp12 = false; }if (keyName != "kR") { bp13 = false; }if (keyName != "kT") { bp14 = false; }
                            if (keyName != "kY") { bp15 = false; }if (keyName != "kU") { bp16 = false; }if (keyName != "kI") { bp17 = false; }
                            if (keyName != "kO") { bp18 = false; }if (keyName != "kP") { bp19 = false; }if (keyName != "kA") { bp20 = false; }
                            if (keyName != "kS") { bp21 = false; }if (keyName != "kD") { bp22 = false; }if (keyName != "kF") { bp23 = false; }
                            if (keyName != "kG") { bp24 = false; }if (keyName != "kH") { bp25 = false; }if (keyName != "kJ") { bp26 = false; }
                            if (keyName != "kK") { bp27 = false; }if (keyName != "kL") { bp28 = false; }if (keyName != "kZ") { bp29 = false; }
                            if (keyName != "kX") { bp30 = false; }if (keyName != "kC") { bp31 = false; }if (keyName != "kV") { bp32 = false; }
                            if (keyName != "kB") { bp33 = false; }if (keyName != "kN") { bp34 = false; }if (keyName != "kM") { bp35 = false; }
                            break; // Прерываем цикл, если клавиша найдена
       
                        }
                    }

                    ImGui::End();

                }
                if (!JTModule->fJEFrame)
                {
                    ImGui::PushFont(font2);
                    ImGui::Text("\nWELLCOME TO JOYSTICKTEST!!");
                    ImGui::PopFont();
                    ImGui::Text("\nCREATED BY HCPP\n");

                }
                ImU32 col = ImGui::GetColorU32(ImVec4(0.34f, 0.06f, 0.98f, 1.00f));
              // ImGui::Text(("_____________________________\n\nCONTROLLER_1: " + bStrStatus + "\nTYPE : " + std::to_string(b_type) + "\n_____________________________").c_str());
                // GLuint gl_id;
               //  ImLoadImageForGL("Test.jpg", &gl_id, 30, 30);
                JTModule->C_XinputControllerStateError = (JTModule->C_XinputControllerState ? true : false);
                if (JTModule->xController1->IsConnected() || JTModule->C_XinputControllerState)
                {
                    ImGui::Text("CONTROLLER CONNECTED!!\n\n");
                    JTModule->C_XinputControllerState = true;
                }
               
                if (!JTModule->C_XinputControllerState) {
                    ImGui::Begin("Error", &JTModule->C_XinputControllerStateError);
                    ImGui::SetCursorPos(ImVec2(20, 40));
                    ImGui::Spinner("scan", 20, 3, col);  ImGui::SameLine(); ImGui::SetCursorPos(ImVec2(100, 50)); ImGui::Text("PLEASE PLUG YOUR CONTROLLER!!\n");
                    JTModule->C_XinputControllerState = false;
                    ImGui::SetCursorPosX(100);
                    if (ImGui::Button("OK", ImVec2(100, 30))) {
                        JTModule->C_XinputControllerState = true;
                    }


                    ImGui::End();
                    //fSndMsg(1);
                }
                if (!JTModule->bShowButtons)
                {
                    if (ImGui::Button("\tJOYSTICKTEST", ImVec2(170.0f, 50.0f)))
                    {
                        JTModule->fJEFrame = true;
                        JTModule->bShowButtons = true;
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("\tVisit Github", ImVec2(170.0f, 50.0f)))
                    {
                        std::system("start https://github.com/hcpp20334");
                    }
                    ImGui::Text(("BULID: 1.2.1 (x64) (OpenGL3.3SSE4.2(C++20 GCC)) \nGPU:" + (fD_gpuModel)+" FPS:" + std::to_string((int64_t)io.Framerate) + " \n MEM : " + std::to_string((int64_t)(fDataMemUsage() / 1024) / 1024) + "MiB]").c_str());
                }
                //
               // ImGui::ColorButton("JoyStickTest", ImVec4(0.90f, 0.65f, 0.65f, 0.45f),1,ImVec2(100.0f,50.0f));
                
                std::string fGPURating[] = {"SHIT","OFFICE DICK","Nice Card","Very Good","Wtf man!! You GPU quantum ?"};
                static float64_t af = 5.5f;
                if (JTModule->bGPUTest) {
                    static uint64_t fDelayToCloseFrameCount = 0;
                   auto InLatency = chrono::high_resolution_clock::now();
                    uint64_t fps_count = io.Framerate;
                    static uint64_t fps_count0 = 0;
                    JTModule->JEApp.ClearFreeMemory();
                    ImGui::Begin("GPU TEST", &JTModule->bGPUTest);
                    ImGui::PushFont(font2);
                    ImGui::SetCursorPosX(30.0f);
                    ImGui::Text("GPU TEST v1.2 OpenGL3.3");
                    ImGui::PopFont();//
                    if (JTModule->stopBench)
                    {
                        
                        ImGui::PushFont(font2);
                        ImGui::SetCursorPosX(30.0f);
                        ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f, 1.0f), ("score:" + std::to_string((14 * JTModule->fGPUScore))).c_str()); ImGui::SameLine();
                        ImGui::PopFont();
                        ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.33f, 1.0f), (" " + fGPURating[id]).c_str());
                        ImGui::SetCursorPos(ImVec2(30.0f,100));
                        ImGui::Text(("\ntime: " + std::to_string(JTModule->fGPUScore0) + "ms").c_str());

                    }
                    ImGui::SetCursorPosX(30.0f);
                    ImGui::SetCursorPosY((ImGui::GetWindowHeight() - 40) / 2);
                    if (ImGui::Button("BENCH", ImVec2(130.0f, 40.0f)))
                    {
                        fDelayToCloseFrameCount = 0;
                        JTModule->renderFrame = true;
                        JTModule->stopBench = false;

                        
                    }
         
                   static  uint64_t imgLoaded = 0;
                    ImGui::SliderInt("Count:", &JTModule->imgCountToRender, 100, 100000, NULL, 1);
                    ImGui::Text("Resolution");
                    ImGui::PushItemWidth(100.0f);
                    ImGui::InputInt("SizeX:", &Ix, 10, 1); ImGui::SameLine(); ImGui::InputInt("SizeY:", &Iy, 10, 1);
                    ImGui::PopItemWidth();
                    
                    if (JTModule->renderFrame) {
                        JTModule->fGPUScore = ImMax((int)fps_count, (int)fps_count0);
                        ImGui::Begin("Render", &JTModule->renderFrame);
                        fps_count0 = io.Framerate;
                        if (fps_count0 == 15) {
                            id = 2;
                        }
                        if (fps_count0 < 15) {
                            id = 2;
                        }
                        if (fps_count0 <= 5) {
                            id = 0;
                        }
                        if (fps_count0 >= 30) {
                            id = 3;
                        }
                        if (fps_count0 >= 60) {
                            id = 4;
                        }
                        
                        ImGui::SetWindowSize(ImVec2(800.0f, 480.0f));
                        ImGui::Text(("GPU:[" + GPU.E_Model+"]\t fps_count:"+std::to_string(fps_count0) +"loaded:["+std::to_string(imgLoaded) +"/" + std::to_string(JTModule->imgCountToRender)+"]"+"dl:"+std::to_string(fDelayToCloseFrameCount)).c_str());
                      // ImGui::Text(("AMD AGS Device info:" + std::to_string(device.localMemoryInBytes / (1024 * 1024)) + std::to_string(device.memoryBandwidth / 1024.0f) + std::to_string(device.sharedMemoryInBytes / (1024 * 1024))).c_str());
                        for (uint64_t imgBufferOffset = 0; imgBufferOffset <= JTModule->imgCountToRender; imgBufferOffset++) {
                           // ImGui::Text(("GPU:[" + GPU.E_Model + "]\t fps_count:" + std::to_string(fps_count) + "loaded:[" + std::to_string(imgLoaded) + "/" + std::to_string(JTModule->imgCountToRender) + "]").c_str());
                            imgLoaded = imgBufferOffset;
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));//
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            ImGui::SameLine();
                            ImGui::Image((void*)(intptr_t)GLArrayBuffer, ImVec2(Ix, Iy));
                            if (imgBufferOffset == JTModule->imgCountToRender) {
                                break;
                            }

                       }
                        fDelayToCloseFrameCount++;
                        if (fDelayToCloseFrameCount > 100) {
                            fDelayToCloseFrameCount = 100;
                            JTModule->renderFrame = false;

                        }
                        //JTModule->renderFrame = false;
                        JTModule->stopBench = true;
                        auto OutLatency = chrono::high_resolution_clock::now();
                        JTModule->fGPUScore0 = chrono::duration_cast<chrono::milliseconds>(OutLatency - InLatency).count();
                        ImGui::End();
                    }
                    ImGui::End();
                } 
                if (fJEUpdate)
                {
                    JTModule->JEApp.ClearFreeMemory();
                    // LPBINDSTATUSCALLBACK st_b;
                    const TCHAR dURL[] = _T("https://github.com/HCPP20334/JoyStickTest/releases/download/JoyStickTest_x64_OpenGL_1.1/JoyStickTest_x64_OpenGL3SSE4.2.zip");
                    const TCHAR dFllePath[] = _T("JoyStickTest_x64_OpenGL3SSE4.2.zip");
                    int64_t fDwChannel_0 = URLDownloadToFile(NULL, NULL, dFllePath, 0, NULL);
                    static bool v_bDown = false;
                    static bool v_bStatus = false;
                    static bool WindowReadBool = false;
                    static  std::string btn_name;
                    static std::string strdata;
                    ImGui::Begin("\tUPDATE CENTER", &fJEUpdate, ImGuiWindowFlags_NoCollapse);
                    ImGui::Text("Read Readme.md to Latest Build!");
                    ImGui::Text("UPDATE CENTER - UPDATE JE TO GITHUB SERVER");
                    ImGui::TextRGBABool((btn_name).c_str(),ImVec4(0,255,120,255),ImVec4(255,0,130,255), v_bStatus);
                    // std::cout << st_b << std::endl;
                    if (WindowReadBool) {
                        ImGui::Begin("README.MD", &WindowReadBool);
                        ImGui::Text((strdata).c_str());
                        ImGui::End();
                    }
                    if (ImGui::Button("Check README.md", ImVec2(160.f, 30.0f))) {
                        WindowReadBool = GUI->OpenMDRelease(&strdata);
                    }
                    ImGui::SameLine();
                    if (ImGui::Button("DOWNLOAD", ImVec2(100.f, 30.0f)))
                    {
                        btn_name = "CONNECTING..";
                        Sleep(13);
                        v_bDown = true;
                    }
                    if (!v_bStatus)
                    {

                        btn_name = "UPDATE FATAL ERROR!!";
                    }
                    if (v_bStatus)
                    {
                        btn_name = "DOWNLOAD OK";
                        btn_name = "UPDATE SUCCEEDED!\t\t\nSAVED TO : . / JEx64_OpenGL3_SSE4.2cpp20";
                        Sleep(13);
                        v_bDown = false;
                    }
                    if (v_bDown)
                    {
                        fDwChannel_0 = URLDownloadToFile(NULL, dURL, dFllePath, 0, NULL);
                        if (SUCCEEDED(fDwChannel_0))
                        {
                            v_bStatus = true;

                          
                            v_bDown = false;

                        }
                        if (FAILED(fDwChannel_0))
                        {
                            v_bStatus = false;
                         
                            v_bDown = false;

                        }
                    }
                    ImGui::End();
                }
                if (JTModule->Gamepad_enable)
                { 
                    ImGuiKeyData* fLS_left = ImGui::GetKeyData(ImGuiKey_GamepadLStickLeft);
                    ImGuiKeyData* fLS_Right = ImGui::GetKeyData(ImGuiKey_GamepadLStickRight);
                    ImGuiKeyData* fLS_Up = ImGui::GetKeyData(ImGuiKey_GamepadLStickUp);
                    ImGuiKeyData* fLS_Down = ImGui::GetKeyData(ImGuiKey_GamepadLStickDown);
                    //
                    ImGuiKeyData* fRS_left = ImGui::GetKeyData(ImGuiKey_GamepadRStickLeft);
                    ImGuiKeyData* fRS_Right = ImGui::GetKeyData(ImGuiKey_GamepadRStickRight);
                    ImGuiKeyData* fRS_Up = ImGui::GetKeyData(ImGuiKey_GamepadRStickUp);
                    ImGuiKeyData* fRS_Down = ImGui::GetKeyData(ImGuiKey_GamepadRStickDown);
                    ImGuiKeyData* fLTv = ImGui::GetKeyData(ImGuiKey_GamepadL2);
                    ImGuiKeyData* fRTv = ImGui::GetKeyData(ImGuiKey_GamepadR2);
                    JTModule->fLX = fLS_Right->AnalogValue - fLS_left->AnalogValue;
                    JTModule->fLY = fLS_Down->AnalogValue - fLS_Up->AnalogValue;
                    JTModule->fRY = fRS_Down->AnalogValue - fRS_Up->AnalogValue;
                    JTModule->fRX = fRS_Right->AnalogValue - fRS_left->AnalogValue;
                    fRTv->Down ? JTModule->fRT += 10 : JTModule->fRT -= 10;
                    fLTv->Down ? JTModule->fLT += 10 : JTModule->fLT -= 10;
                    if (JTModule->fRT > 255) {
                        JTModule->fRT = 255;
                    }
                    if (JTModule->fLT > 255) {
                        JTModule->fLT = 255;
                    }
                    if (JTModule->fRT <= 0) {
                        JTModule->fRT = 0;
                    }
                    if (JTModule->fLT <= 0) {
                        JTModule->fLT = 0;
                    }
                    if (io.KeysDown[ImGuiKey_GamepadFaceRight]) { JTModule->fB_b = JTModule->fB_b + 0.1f; if (JTModule->fB_b > 1.000f) { JTModule->fB_b = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadFaceDown]) { JTModule->fB_a = JTModule->fB_a + 0.1f; if (JTModule->fB_a > 1.000f) { JTModule->fB_a = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadFaceLeft]) { JTModule->fB_x = JTModule->fB_x + 0.1f; if (JTModule->fB_x > 1.000f) { JTModule->fB_x = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadFaceUp]) { JTModule->fB_y = JTModule->fB_y + 0.1f; if (JTModule->fB_y > 1.000f) { JTModule->fB_y = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadR1]) { JTModule->fB_rs = JTModule->fB_rs + 0.1f; if (JTModule->fB_rs > 1.000f) { JTModule->fB_rs = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadL1]) { JTModule->fB_ls = JTModule->fB_ls + 0.1f; if (JTModule->fB_ls > 1.000f) { JTModule->fB_ls = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadDpadUp]) { JTModule->fB_du = JTModule->fB_du + 0.1f; if (JTModule->fB_du > 1.000f) { JTModule->fB_du = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadDpadDown]) { JTModule->fB_dd = JTModule->fB_dd + 0.1f; if (JTModule->fB_dd > 1.000f) { JTModule->fB_dd = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadDpadLeft]) { JTModule->fB_dl = JTModule->fB_dl + 0.1f; if (JTModule->fB_dl > 1.000f) { JTModule->fB_dl = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadDpadRight]) { JTModule->fB_dr = JTModule->fB_dr + 0.1f; if (JTModule->fB_dr > 1.000f) { JTModule->fB_dr = 1.000f; } }
                    if (io.KeysDown[ImGuiKey_GamepadStart]) { JTModule->b_Start = true; }
                    if (io.KeysDown[ImGuiKey_GamepadBack]) { JTModule->b_Back = true; }
                    //
                    if (!io.KeysDown[ImGuiKey_GamepadFaceRight]) { JTModule->fB_b = JTModule->fB_b - 0.1f; if (JTModule->fB_b < 0.1f) { JTModule->fB_b = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadFaceDown]) { JTModule->fB_a = JTModule->fB_a - 0.1f; if (JTModule->fB_a < 0.1f) { JTModule->fB_a = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadFaceLeft]) { JTModule->fB_x = JTModule->fB_x - 0.1f; if (JTModule->fB_x < 0.1f) { JTModule->fB_x = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadFaceUp]) { JTModule->fB_y = JTModule->fB_y - 0.1f; if (JTModule->fB_y < 0.1f) { JTModule->fB_y = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadR1]) { JTModule->fB_rs = JTModule->fB_rs - 0.1f; if (JTModule->fB_rs < 0.1f) { JTModule->fB_rs = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadL1]) { JTModule->fB_ls = JTModule->fB_ls - 0.1f; if (JTModule->fB_ls < 0.1f) { JTModule->fB_ls = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadDpadUp]) { JTModule->fB_du = JTModule->fB_du - 0.1f; if (JTModule->fB_du < 0.1f) { JTModule->fB_du = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadDpadDown]) { JTModule->fB_dd = JTModule->fB_dd - 0.1f; if (JTModule->fB_dd < 0.1f) { JTModule->fB_dd = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadDpadLeft]) { JTModule->fB_dl = JTModule->fB_dl - 0.1f; if (JTModule->fB_dl < 0.1f) { JTModule->fB_dl = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadDpadRight]) { JTModule->fB_dr = JTModule->fB_dr - 0.1f; if (JTModule->fB_dr < 0.1f) { JTModule->fB_dr = 0.0f; } }
                    if (!io.KeysDown[ImGuiKey_GamepadStart]) { JTModule->b_Start = false; }
                    if (!io.KeysDown[ImGuiKey_GamepadBack]) { JTModule->b_Back = false; }
                }
                if (!JTModule->Gamepad_enable)
                {
                    //button
                    //  detector
                    JTModule->fLX = (JTModule->xController1->GetState().Gamepad.sThumbLX / 32768.0f);
                    JTModule->fLY = (JTModule->xController1->GetState().Gamepad.sThumbLY / 32768.0f);
                    JTModule->fRX = (JTModule->xController1->GetState().Gamepad.sThumbRX / 32768.0f);
                    JTModule->fRY = (JTModule->xController1->GetState().Gamepad.sThumbRY / 32768.0f);
                    JTModule->fLT = (JTModule->xController1->GetState().Gamepad.bLeftTrigger);
                    JTModule->fRT = (JTModule->xController1->GetState().Gamepad.bRightTrigger);
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B) { JTModule->fB_b = JTModule->fB_b + 0.1f; if (JTModule->fB_b > 1.000f) { JTModule->fB_b = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A) { JTModule->fB_a = JTModule->fB_a + 0.1f; if (JTModule->fB_a > 1.000f) { JTModule->fB_a = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X) { JTModule->fB_x = JTModule->fB_x + 0.1f; if (JTModule->fB_x > 1.000f) { JTModule->fB_x = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y) { JTModule->fB_y = JTModule->fB_y + 0.1f; if (JTModule->fB_y > 1.000f) { JTModule->fB_y = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) { JTModule->fB_rs = JTModule->fB_rs + 0.1f; if (JTModule->fB_rs > 1.000f) { JTModule->fB_rs = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) { JTModule->fB_ls = JTModule->fB_ls + 0.1f; if (JTModule->fB_ls > 1.000f) { JTModule->fB_ls = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) { JTModule->fB_du = JTModule->fB_du + 0.1f; if (JTModule->fB_du > 1.000f) { JTModule->fB_du = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) { JTModule->fB_dd = JTModule->fB_dd + 0.1f; if (JTModule->fB_dd > 1.000f) { JTModule->fB_dd = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) { JTModule->fB_dl = JTModule->fB_dl + 0.1f; if (JTModule->fB_dl > 1.000f) { JTModule->fB_dl = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) { JTModule->fB_dr = JTModule->fB_dr + 0.1f; if (JTModule->fB_dr > 1.000f) { JTModule->fB_dr = 1.000f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_START) { JTModule->b_Start = true; }
                    if (JTModule->xController1->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_BACK) { JTModule->b_Back = true; }
                    //
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_B) { JTModule->fB_b = JTModule->fB_b - 0.1f; if (JTModule->fB_b < 0.1f) { JTModule->fB_b = 0.0f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_A) { JTModule->fB_a = JTModule->fB_a - 0.1f; if (JTModule->fB_a < 0.1f) { JTModule->fB_a = 0.0f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_X) { JTModule->fB_x = JTModule->fB_x - 0.1f; if (JTModule->fB_x < 0.1f) { JTModule->fB_x = 0.0f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_Y) { JTModule->fB_y = JTModule->fB_y - 0.1f; if (JTModule->fB_y < 0.1f) { JTModule->fB_y = 0.0f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_RIGHT_SHOULDER) {JTModule->fB_rs = JTModule->fB_rs - 0.1f; if (JTModule->fB_rs < 0.1f) {JTModule->fB_rs = 0.0f;}}
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_LEFT_SHOULDER) {JTModule->fB_ls = JTModule->fB_ls - 0.1f; if (JTModule->fB_ls < 0.1f) {JTModule->fB_ls = 0.0f;}}
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_UP) {JTModule->fB_du = JTModule->fB_du - 0.1f; if (JTModule->fB_du < 0.1f) {JTModule->fB_du = 0.0f;}}
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_DOWN) {JTModule->fB_dd = JTModule->fB_dd - 0.1f; if (JTModule->fB_dd < 0.1f) {JTModule->fB_dd = 0.0f;}}
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_LEFT) { JTModule->fB_dl = JTModule->fB_dl - 0.1f; if (JTModule->fB_dl < 0.1f) { JTModule->fB_dl = 0.0f;}}
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_DPAD_RIGHT) { JTModule->fB_dr = JTModule->fB_dr - 0.1f; if (JTModule->fB_dr < 0.1f) { JTModule->fB_dr = 0.0f; } }
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_START) { JTModule->b_Start = false; }
                    if (JTModule->xController1->GetState().Gamepad.wButtons != XINPUT_GAMEPAD_BACK) { JTModule->b_Back = false; }
                }
                //
                if (JTModule->fJEFrame)
                {
                    ImGui::SameLine();
                    ImGui::SetCursorPosX(700);
                    if (ImGui::Button("<-", ImVec2(50.0f,50.0f)))                           // Buttons return true when clicked (most widgets return true when edited/activated)
                    {
                        JTModule->fJEFrame = false;
                        JTModule->bShowButtons = false;
                    }
                    static bool dbg_b = false;
                    if (GetAsyncKeyState('N')) {
                        JTModule->fB_a  = RD->frand(1);
                        JTModule->fB_x  = RD->frand(1);
                        JTModule->fB_y  = RD->frand(1);
                        JTModule->fB_b  = RD->frand(1);
                        JTModule->fB_rs = RD->frand(1);
                        JTModule->fB_ls = RD->frand(1);
                        JTModule->fB_du = RD->frand(1);
                        JTModule->fB_dd = RD->frand(1);
                        JTModule->fLY   = RD->frand(1);
                        JTModule->fRY   = RD->frand(1);
                        JTModule->fLX   = RD->frand(1);
                        JTModule->fRX   = RD->frand(1);
                        JTModule->fLT   = RD->frand(255);
                        JTModule->fRT   = RD->frand(255);
                        JTModule->fB_dl = RD->frand(1);
                        JTModule->fB_dr = RD->frand(1);
                        dbg_b = true;
                        JTModule->b_Start = dbg_b ? true : false;
                        JTModule->b_Back = dbg_b ? true : false;
                    }
                    //
                    static bool bSliders = true;
                    JTModule->JEApp.ClearFreeMemory();
                    //bShowButtons = false;
                    ImGui::SetCursorPosX(128); ImGui::SetCursorPosY(30);
                    ImGui::CustomToggle("Lmotor", &JTModule->fL_motor); ImGui::SameLine(); ImGui::CustomToggle("Rmotor", &JTModule->fR_motor); ImGui::SameLine(); ImGui::CustomToggle("Sliders:", &bSliders);
                    ImGui::SetCursorPosY(60);
                    ImGui::SetCursorPosX(220);
                    ImGui::CircleAxisXY("LS", JTModule->fLX, (!JTModule->fInvertYBool ? JTModule->fLY* (-1): JTModule->fLY)); ImGui::SameLine();
                    ImGui::CircleAxisXY("RS", JTModule->fRX , (!JTModule->fInvertYBool ? JTModule->fRY * (-1) : JTModule->fRY));
                    ImGui::SetCursorPosX(128); ImGui::SetCursorPosY(220);
                    if (bSliders) {
                    ImGui::TextToBool("START",JTModule->b_Start); ImGui::SameLine(); ImGui::SetCursorPosY(220); ImGui::TextToBool("BACK",  JTModule->b_Back);
                        ImGui::PushItemWidth(200.0f);
                        ImGui::SetCursorPosX(128); ImGui::SliderFloat("A  ", &JTModule->fB_a, 0.0f, 1.0f);  ImGui::SameLine(); ImGui::SliderFloat("RT", &JTModule->fRT, 0.0f, 255.0f);
                        ImGui::SetCursorPosX(128); ImGui::SliderFloat("X  ", &JTModule->fB_x, 0.0f, 1.0f);  ImGui::SameLine(); ImGui::SliderFloat("LT", &JTModule->fLT, 0.0f, 255.0f);
                        ImGui::SetCursorPosX(128); ImGui::SliderFloat("Y  ", &JTModule->fB_y, 0.0f, 1.0f);  ImGui::SameLine(); ImGui::SliderFloat(" L", &JTModule->fB_dl, 0.0f, 1.0f);
                        ImGui::SetCursorPosX(128); ImGui::SliderFloat("B  ", &JTModule->fB_b, 0.0f, 1.0f);  ImGui::SameLine(); ImGui::SliderFloat(" R", &JTModule->fB_dr, 0.0f, 1.0f);
                        ImGui::SetCursorPosX(128); ImGui::SliderFloat("RB ", &JTModule->fB_rs, 0.0f, 1.0f); ImGui::SameLine(); ImGui::SliderFloat("UP", &JTModule->fB_du, 0.0f, 1.0f);
                        ImGui::SetCursorPosX(128); ImGui::SliderFloat("LB ", &JTModule->fB_ls, 0.0f, 1.0f); ImGui::SameLine(); ImGui::SliderFloat(" D", &JTModule->fB_dd, 0.0f, 1.0f);
                        ImGui::PopItemWidth();
                    }
                    else {
                        ImGui::BeginChild("Controls", ImVec2(400, 200), ImGuiChildFlags_Border | ImGuiChildFlags_FrameStyle);
                        {
                            const float button_size = 32.0f;
                            const float spacing = 10.0f;
                            const float center_x = ImGui::GetWindowWidth() * 0.5f;

                            // Верхние триггеры (LB/LT и RB/RT)
                            ImGui::SetCursorPos(ImVec2(center_x - 150.0f - spacing, 10.0f));
                            ImGui::ButtonGamepad("LB", JTModule->fB_ls);
                            ImGui::SameLine(0, 200.0f);
                            ImGui::ButtonGamepad("RB", JTModule->fB_rs);

                            ImGui::SetCursorPos(ImVec2(center_x - 150.0f - spacing, 50.0f));
                            ImGui::ButtonGamepad("LT", JTModule->fLT);
                            ImGui::SameLine(0, 200.0f);
                            ImGui::ButtonGamepad("RT", JTModule->fRT);

                            // Центральная область (крестовина и кнопки ABXY)
                            ImVec2 dpad_pos(center_x - 150.0f, 80.0f);
                            ImVec2 buttons_pos(center_x + 40.0f, 80.0f);

                            // Крестовина (D-pad)
                            ImGui::SetCursorPos(ImVec2(dpad_pos.x + button_size, dpad_pos.y));
                            ImGui::ButtonGamepad("U", JTModule->fB_du);
                            ImGui::SetCursorPos(ImVec2(dpad_pos.x, dpad_pos.y+30));
                            ImGui::ButtonGamepad("L", JTModule->fB_dl);
                            ImGui::SameLine();
                            ImGui::SetCursorPosX(dpad_pos.x + button_size * 2);
                            ImGui::ButtonGamepad("R", JTModule->fB_dr);
                            ImGui::SetCursorPos(ImVec2(dpad_pos.x + button_size, dpad_pos.y + button_size * 2));
                            ImGui::ButtonGamepad("D", JTModule->fB_dd);

                            // Кнопки ABXY
                            ImGui::SetCursorPos(buttons_pos);
                            ImGui::ButtonGamepad("Y", JTModule->fB_y);
                            ImGui::SetCursorPos(ImVec2(buttons_pos.x - button_size, buttons_pos.y + button_size));
                            ImGui::ButtonGamepad("X", JTModule->fB_x);
                            ImGui::SameLine();
                            ImGui::SetCursorPosX(buttons_pos.x + button_size);
                            ImGui::ButtonGamepad("B", JTModule->fB_b);
                            ImGui::SetCursorPos(ImVec2(buttons_pos.x, buttons_pos.y + button_size * 2));
                            ImGui::ButtonGamepad("A", JTModule->fB_a);

                            // Нижние кнопки (Start/Back)
                            ImGui::SetCursorPos(ImVec2(center_x - 40.0f, 160.0f));
                            ImGui::TextToBool("START", JTModule->b_Start);
                            ImGui::SameLine(0, 80.0f);
                            ImGui::TextToBool("BACK", JTModule->b_Back);
                        }
                        ImGui::EndChild();
                    }
                    if (JTModule->v_bInvertVibValue)
                    {
                        //WriteConfigJE.is_open();

                        JTModule->xController1->Vibrate(JTModule->v_Lmotor, JTModule->v_Rmotor);
                    }
                    else
                    {
                        JTModule->xController1->Vibrate((JTModule->v_Lmotor * -1), (JTModule->v_Rmotor * -1));

                    }

                    if (JTModule->fR_motor)
                    {
                        // ImGui::InputInt("Rduration", &v_Rmotor, 1, 100);
                        ImGui::PushItemWidth(150.0f);
                        ImGui::SetCursorPosX(365); ImGui::SliderInt("Rduration", &JTModule->v_Rmotor, 0.0f, 1000.0f);
                        ImGui::SameLine();
                        ImGui::PopItemWidth();
                    }
                    if (JTModule->fL_motor)
                    {
                        ImGui::PushItemWidth(150.0f);
                        ImGui::SetCursorPosX(128); ImGui::SliderInt("Lduration", &JTModule->v_Lmotor, 0.0f, 1000.0f);
                        ImGui::PopItemWidth();
                        //ImGui::InputInt("Lduration", &v_Lmotor, 1, 100);
                    }
                    if (!JTModule->fL_motor || !JTModule->fR_motor)
                    {
                        JTModule->v_Lmotor = 0;
                        JTModule->v_Rmotor = 0;
                    }
                }
                // static bool bCPUTest = false;
                 //ImGui::ColorEdit3("clear color", (float*)&JTModule->clear_color); // Edit 3 floats representing a color
                 // io.Fonts->AddFontFromFileTTF("./WhiteRabbit.ttf", 15.0f);
                
           
                ImGui::End();
            
        }
        if (JTModule->fCAboutW)
        {
            ImGui::Begin("\tAbout", &JTModule->fCAboutW, ImGuiWindowFlags_NoCollapse);
            ImGui::PushFont(font2);
            ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f,1.0f), "JOYSTICKTEST");//Build 1.1\n
            ImGui::PopFont();
            ImGui::PushFont(font3);
            ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f, 1.0f), "Build 1.2.1\n");//Build 1.1\n
            ImGui::PopFont();
            ImGui::TextColored(ImVec4(0.20f, 1.0f, 0.40f, 1.0f),"COMPILED C++20 (GCC) Visual Studio 2022 x64\nBackendAPI: OpenGL3.3\nInstruction Set:SSE4.2,x64,IA-64");
          
            
           // std::cout << &fJ_vendor << &fJ_rendered << "\n";
            if (ImGui::Button("OK")){ JTModule->fCAboutW = false; }
            ImGui::Text("Optimized"); ImGui::SameLine();
            ImGui::Image((void*)(intptr_t)GLArrayBuffer_1, ImVec2(128.0f, 64.0f));
            ImGui::End();
        }
        if (JTModule->bCPUTest)
        {
            static int64_t v_Cscore = 0;
            static int64_t v_CFirst = 0;
            static int64_t v_COutV = 0;
            static int64_t fV = 0;
            static int64_t fc_0 = 0;
            static bool cp_state = false;
            std::string fDebugData;
            ImGui::Begin("\tCPU Test", &JTModule->bCPUTest, ImGuiWindowFlags_NoCollapse);

            // ImGui::Text(("cores: " + std::to_string(dDataCPU(3)) + "\nThreads: " + std::to_string(dDataCPU(4))).c_str());
            ImGui::TextColored(ImVec4(0.118f, 0.881f, 0.43f, 1.10f), "Test CPU");
            ImGui::PushFont(font2);
            ImGui::Text(("\t\t" + JTModule->fBuffer_data).c_str());
            ImGui::PopFont();
            ImGui::Text(("\ninfo:\n" + fDebugData).c_str());
            //std::cout << "Cycle:" << fT_cpuSpeed << "Score" << v_Cscore << std::endl;
            ImGui::SetCursorPosX((ImGui::GetWindowWidth() - 130) / 2);
            if (ImGui::Button("BENCH", ImVec2(130.0f, 40.0f)))
            {
                v_Cscore = ld_V(&JTModule->fBuffer_data, &fDebugData);

            }
            
            ImGui::End();
            
        }
       
        // 3. Show another simple window.
         
        // Rendering
      ImGui::Render();
        glViewport(0, 0, 400, 800);
        glClearColor(JTModule->clear_color.x, JTModule->clear_color.y, JTModule->clear_color.z, JTModule->clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Present
        ::SwapBuffers(g_MainWindow.hDC);

    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceWGL(hwnd, &g_MainWindow);
    wglDeleteContext(g_hRC);
    ::DestroyWindow(hwnd);
    ::UnregisterClassW(wc.lpszClassName, wc.hInstance);

    return 0;
}

// Helper functions
bool CreateDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    HDC hDc = ::GetDC(hWnd);
    PIXELFORMATDESCRIPTOR pfd = { 0 };
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 32;

    const int pf = ::ChoosePixelFormat(hDc, &pfd);
    if (pf == 0)
        return false;
    if (::SetPixelFormat(hDc, pf, &pfd) == FALSE)
        return false;
    ::ReleaseDC(hWnd, hDc);

    data->hDC = ::GetDC(hWnd);
    if (!g_hRC)
        g_hRC = wglCreateContext(data->hDC);
    return true;
}

void CleanupDeviceWGL(HWND hWnd, WGL_WindowData* data)
{
    wglMakeCurrent(nullptr, nullptr);
    ::ReleaseDC(hWnd, data->hDC);
}

// Forward declare message handler from imgui_impl_win32.cpp
extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Win32 message handler
// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (wParam != SIZE_MINIMIZED)
        {
            g_Width = LOWORD(lParam);
            g_Height = HIWORD(lParam);
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menuS
            return 0;
        break;
    case WM_DESTROY:
        exit(0);
        return 0;
    }
    return ::DefWindowProcW(hWnd, msg, wParam, lParam);
}
